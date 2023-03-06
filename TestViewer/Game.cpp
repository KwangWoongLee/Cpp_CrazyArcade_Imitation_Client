#include "stdafx.h"
#include "ServerSession.h"
#include "Proto/protocol.pb.h"

shared_ptr<Game> gGame = make_shared<Game>();

Game::Game()
	: mWindow(nullptr)
	, mRenderer(nullptr)
{
}

bool Game::Init()
{
	// SDL �ʱ�ȭ
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// SDL ������ ����
	mWindow = SDL_CreateWindow("2d Game Client", 270, 50, 1000, 1000 , 0);
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

	
	mTicksCount = SDL_GetTicks();

    return true;
}



void Game::GenerateOutput(const google::protobuf::RepeatedPtrField<Protocol::PActor>& actors)
{
	//�ĸ����(����) �ʱ�ȭ
	//���� �׸��� �������� �ʱ�ȭ
	SDL_SetRenderDrawColor(mRenderer, 220, 220, 220, 255);
	//���� �׸��� �������� �ʱ�ȭ
	SDL_RenderClear(mRenderer);

	for (auto actor : actors)
	{
		SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);


		SDL_FRect r;
		r.w = static_cast<int>(2);
		r.h = static_cast<int>(2);
		r.x = actor.position().x();
		r.y = actor.position().y();

		SDL_RenderDrawRectF(mRenderer, &r);
	}

	//�������(���÷���)�� �ĸ���� ��ü
	SDL_RenderPresent(mRenderer);
 }

