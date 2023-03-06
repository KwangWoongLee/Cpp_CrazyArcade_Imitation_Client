#include "stdafx.h"
#include "Reciever.h"
#include "ServerSession.h"


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

	// SDL �ʱ�ȭ
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// SDL ������ ����
	mWindow = SDL_CreateWindow("2d Game Client", 270, 50, mGameScale * (mMapRange[1] - 1) * mTileSizeX, mGameScale * (mMapRange[3] - 1) * mTileSizeY , 0);
	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	//SDL ������ ���� , ��������ȭ �� �׷��� �ϵ���� ���
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	//PNG�� �����ϴ� SDL Image �ʱ�ȭ
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
		return false;
	}

	if (gInputManager->Init() == false)
		return false;

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
		//���� �б���� TODO:�α� ����ó��
		return false;
	}

	ifstream collisionFile(collisionFileName.data());
	if (true == collisionFile.fail())
	{
		//���� �б���� TODO:�α� ����ó��
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
	// actor �Ҹ��ڿ��� actor ��ü�� ��� ������ ������ ��츦 ���
	while (!mActors.empty())
	{
		auto actor = mActors.back();
		actor = nullptr;
	}
}

void Game::RunLoop()
{
	//������ ���� - ������ ������ ���� ��Ÿ�ð��� ��ǥ���� ������� �ش� �ð�(16ms)���� ���
	//����ȯ���� �޶� FPS�� �޶����� ������ �޶��� �� �ֱ� ������ ���
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 100))
		;

	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.f;
	mTicksCount = SDL_GetTicks();


	//��Ÿ �ִ� �ð����� ����
	if (deltaTime > 0.2f)
	{
		deltaTime = 0.2f;
	}


	ProcessInput();
	ProcessRecv();
	gInputManager->Send();
	UpdateGame(deltaTime);
	GenerateOutput();
}



ActorRef Game::FindActor(uint64 id)
{
	if (mIdToActor.find(id) == mIdToActor.end())
		return nullptr;

	return mIdToActor[id];
}

void Game::ProcessInput()
{
	gInputManager->PrepareForUpdate();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}

	KeyboardState keyState = gInputManager->GetState();
	if (keyState.GetKeyState(SDL_SCANCODE_ESCAPE)
		== EReleased)
	{
		mIsRunning = false;
	}

	gInputManager->Update();
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


		if (actor->GetState() != State::WANT_DIE)
		{
			actor->Update(deltaTime);
		}

		//�� ���̿� ���� ��
		if (actor->GetState() == State::WANT_DIE)
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
	//�ĸ����(����) �ʱ�ȭ
	//�׸��� ���� ����
	SDL_SetRenderDrawColor(mRenderer, 220, 220, 220, 255);
	//���� �׸��� �������� �ʱ�ȭ
	SDL_RenderClear(mRenderer);

	//TODO:�׸���
	for (auto sprite : mSprites)
	{
		sprite->Draw(mRenderer, GetGameScale());
	}

	
	//�������(���÷���)�� �ĸ���� ��ü
	SDL_RenderPresent(mRenderer);
 }


void Game::Shutdown()
{
	//UnloadData();
	IMG_Quit();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::AddActor(ActorRef actor)
{
	if (actor->mType == Protocol::ACTOR_TYPE_PLAYER)
		mPlayers.push_back(actor);

	mIdToActor[actor->GetServerId()] = actor;
	
	//Actor ������Ʈ ���̶��, �ӽ�Actor Vector�� Pending
	if (mIsUpdatingActors)
	{
		mPendingActors.emplace_back(actor);
	}
	else
	{
		mActors.emplace_back(actor);
	}
}

void Game::RemoveActor(ActorRef actor)
{
	if (auto iter = mIdToActor.find(actor->GetServerId()); iter != mIdToActor.end())
		mIdToActor.erase(iter);
	
	//actor ��ü�� delete�� ��, ~Actor()�� ���� ȣ��
	//actor pending vector�� ����actor vector ��ο� �ִٸ� �����ش�.  
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

void Game::AddSprite(SpriteComponentRef sprite)
{
	//�׸��� ������ ���� sprite vector�� �ڵ�����
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

void Game::RemoveSprite(SpriteComponentRef sprite)
{
	auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
	mSprites.erase(iter);
}

void Game::RoomQuit()
{
	auto iter = mPlayers.begin();
	for (; iter != mPlayers.end();)
	{
		RemoveActor(*iter);
		iter = mPlayers.erase(iter);
	}


}

SDL_Texture* Game::GetTexture(const std::string& fileName)
{
	SDL_Texture* tex = nullptr;

	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end())
	{
		//texture ��Ȱ��
		tex = iter->second;
	}
	else
	{
		SDL_Surface* surf = IMG_Load(fileName.c_str());
		if (!surf)
		{
			SDL_Log("Failed to load texture file %s", fileName.c_str());
			return nullptr;
		}

		//�÷�Ű ����
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 0, 255));


		tex = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_FreeSurface(surf);
		if (!tex)
		{
			SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
			return nullptr;
		}

		mTextures.emplace(fileName.c_str(), tex);
	}
	return tex;
}
