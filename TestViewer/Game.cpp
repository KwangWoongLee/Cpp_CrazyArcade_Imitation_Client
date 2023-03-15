#include "stdafx.h"
#include "ServerSession.h"
#include "Proto/protocol.pb.h"
#include "ConfigManager.h"

shared_ptr<Game> gGame = make_shared<Game>();

Game::Game()
	: mWindow(nullptr)
	, mRenderer(nullptr)
{
}

bool Game::Init()
{
	// SDL 초기화
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// SDL 윈도우 생성
	mWindow = SDL_CreateWindow("2d Game Client", 270, 50, 1000, 1000 , 0);
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

	TTF_Init();

	string fontPath = gConfigManager->ProjectPath;
	fontPath += "\\Config\\H2GPRM.TTF";

	font = TTF_OpenFont(fontPath.c_str(), 15);


	SDL_Color color = { 255, 0, 255, SDL_ALPHA_OPAQUE };
	string view = "VIEW SIZE : ";
	view += to_string(viewSize);
	SDL_Surface* surface = TTF_RenderText_Blended(font, view.c_str(), color);
	mViewTexture = SDL_CreateTextureFromSurface(mRenderer, surface);
	SDL_FreeSurface(surface);

	
	mTicksCount = SDL_GetTicks();

    return true;
}



void Game::GenerateOutput(const google::protobuf::RepeatedPtrField<Protocol::Pos>& poss)
{
	//후면버퍼(게임) 초기화
	//현재 그리기 색상으로 초기화
	SDL_SetRenderDrawColor(mRenderer, 220, 220, 220, 255);
	//현재 그리기 색상으로 초기화
	SDL_RenderClear(mRenderer);

	SDL_Rect r = { 0, 0, 100, 30 };
	SDL_RenderCopy(mRenderer, mViewTexture, NULL, &r);

	SDL_Color color = { 255, 0, 255, SDL_ALPHA_OPAQUE };
	string delay = "Delay : ";
	delay += to_string(delayTick);
	SDL_Surface* delaysurface = TTF_RenderText_Blended(font, delay.c_str(), color);
	SDL_Texture* delayTexture = SDL_CreateTextureFromSurface(mRenderer, delaysurface);
	SDL_FreeSurface(delaysurface);

	r = { 0, 40, 100, 30 };
	SDL_RenderCopy(mRenderer, delayTexture, NULL, &r);
	SDL_DestroyTexture(delayTexture);

	string count = "ActorCount : ";
	count += to_string(poss.size());
	SDL_Surface* countSurface = TTF_RenderText_Blended(font, count.c_str(), color);
	SDL_Texture* countTexture = SDL_CreateTextureFromSurface(mRenderer, countSurface);
	SDL_FreeSurface(countSurface);

	r = { 0, 80, 100, 30 };
	SDL_RenderCopy(mRenderer, countTexture, NULL, &r);
	SDL_DestroyTexture(countTexture);

	string zone = "ZoneCount : ";
	zone += to_string(zoneCount);
	SDL_Surface* zoneSurface = TTF_RenderText_Blended(font, zone.c_str(), color);
	SDL_Texture* zoneTexture = SDL_CreateTextureFromSurface(mRenderer, zoneSurface);
	SDL_FreeSurface(zoneSurface);

	r = { 0, 120, 100, 30 };
	SDL_RenderCopy(mRenderer, zoneTexture, NULL, &r);
	SDL_DestroyTexture(zoneTexture);


	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);

	for (int i = 1000/zoneCount; i < 1000; i = i + 1000 / zoneCount)
	{
		SDL_RenderDrawLine(mRenderer, i, 0, i, 1000);
		SDL_RenderDrawLine(mRenderer, 0, i, 1000, i);
	}

	SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);


	for (auto pos : poss)
	{
		

		SDL_FRect r;
		r.w = static_cast<int>(2);
		r.h = static_cast<int>(2);
		r.x = pos.x();
		r.y = pos.y();

		SDL_RenderDrawRectF(mRenderer, &r);
	}

	//전면버퍼(디스플레이)와 후면버퍼 교체
	SDL_RenderPresent(mRenderer);
 }

