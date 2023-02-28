#include "stdafx.h"
#include "ServerSession.h"
#include "Reciever.h"

shared_ptr<Game> gGame = make_shared<Game>();

Game::Game()
    :mIsRunning(true)
    ,mWindow(nullptr)
	, mRenderer(nullptr)
	, mIsUpdatingActors(false)
	, mTileSizeX(0)
	, mTileSizeY(0)
{
}

bool Game::Init()
{
	LoadData();

	// SDL 초기화
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// SDL 윈도우 생성
	mWindow = SDL_CreateWindow("2d Game Client", 270, 50, mGameScale * (mMapRange[1] - 1) * mTileSizeX, mGameScale * (mMapRange[3] - 1) * mTileSizeY , 0);
	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	//SDL 렌더러 생성 , 수직동기화 및 그래픽 하드웨어 사용
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	
	mTicksCount = SDL_GetTicks();

    return true;
}


bool Game::LoadData(std::string_view mapFileName, std::string_view collisionFileName)
{
	mTileSizeX = 32;
	mTileSizeY = 32;
	mGameScale = 2;

	ifstream mapfile(mapFileName.data());
	if (true == mapfile.fail())
	{
		//파일 읽기실패 TODO:로그 예외처리
		return false;
	}

	ifstream collisionFile(collisionFileName.data());
	if (true == collisionFile.fail())
	{
		//파일 읽기실패 TODO:로그 예외처리
		return false;
	}



	string cell;
	string line;

	for (auto i = 0; i < 4; ++i)
	{
		getline(mapfile, line);
		stringstream lineStream(line);
		getline(lineStream, cell, ',');
		mMapRange.push_back(stoi(cell));
	}
	return true;

}

void Game::UnloadData()
{
	// actor 소멸자에서 actor 객체를 모두 지우지 못했을 경우를 대비
	while (!mActors.empty())
	{
		auto actor = mActors.back();
		actor = nullptr;
	}
}

void Game::RunLoop()
{
	//프레임 제한 - 마지막 프레임 이후 델타시간이 목표보다 적을경우 해당 시간(16ms)까지 대기
	//실행환경이 달라 FPS가 달라지면 동작이 달라질 수 있기 때문에 사용
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 100))
		;

	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.f;
	mTicksCount = SDL_GetTicks();


	//델타 최대 시간값을 고정
	if (deltaTime > 0.2f)
	{
		deltaTime = 0.2f;
	}

	ProcessRecv();
	if (OnNetwork == false) 
		return;
	UpdateGame(deltaTime);
	GenerateOutput();
}



ActorRef Game::FindActor(uint64 id)
{
	if (mIdToActor.find(id) == mIdToActor.end())
		return nullptr;

	return mIdToActor[id];
}

void Game::ProcessRecv()
{
	gReciever->Execute();
}

void Game::UpdateGame(float deltaTime)
{

	for (int i = 0, c = mActors.size(); i < c; ++i)
	{
		ActorRef actor = mActors[i];


		if (actor->GetState() != Actor::State::WANT_DIE)
		{
			actor->Update(deltaTime);
		}

		//그 사이에 죽을 때
		if (actor->GetState() == Actor::State::WANT_DIE)
		{
			actor->Die();
			RemoveActor(actor);
			--i;
			--c;
		}
	}
}

void Game::GenerateOutput()
{
	//후면버퍼(게임) 초기화
	//그리기 색상 지정
	SDL_SetRenderDrawColor(mRenderer, 220, 220, 220, 255);
	//현재 그리기 색상으로 초기화
	SDL_RenderClear(mRenderer);

	//TODO:그리기
	for (auto sprite : mSprites)
	{
		sprite->Draw(mRenderer, GetGameScale());
	}


	//전면버퍼(디스플레이)와 후면버퍼 교체
	SDL_RenderPresent(mRenderer);
 }


void Game::Shutdown()
{
	//UnloadData();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::AddActor(ActorRef actor)
{
	mIdToActor[actor->GetServerId()] = actor;
	PrevActors.insert(actor->GetServerId());
	
	//Actor 업데이트 중이라면, 임시Actor Vector에 Pending
	if (mIsUpdatingActors)
	{
		mPendingActors.emplace_back(actor);
	}
	else
	{
		mActors.emplace_back(actor);
	}
}

void Game::AddSprite(SpriteComponentRef sprite)
{
	//그리기 순서에 맞춰 sprite vector에 자동정렬
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();
	for (;
		iter != mSprites.end();
		++iter)
	{
		if (myDrawOrder < (*iter)->GetDrawOrder())
		{
			break;
		}
	}

	mSprites.insert(iter, sprite);
}

void Game::RemoveActor(ActorRef actor)
{
	PrevActors.erase(actor->GetServerId());

	if (auto iter = mIdToActor.find(actor->GetServerId()); iter != mIdToActor.end())
		mIdToActor.erase(iter);
	
	//actor 객체가 delete될 때, ~Actor()에 의해 호출
	//actor pending vector와 실제actor vector 모두에 있다면 지워준다.  
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end())
	{
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}


	iter = std::find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end())
	{
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
	}
}
