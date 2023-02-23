#include "stdafx.h"
#include "Game.h"

Player::Player()
{
	SetScale(0.5f);
}

Player::~Player()
{
}

void Player::Init()
{
	AnimationComponentRef asc = std::make_shared<AnimationComponent>(shared_from_this(), 200);

	SDL_Texture* idle = gGame->GetTexture("Assets/idle.bmp");
	SDL_Texture* down = gGame->GetTexture("Assets/down.bmp");
	SDL_Texture* left = gGame->GetTexture("Assets/left.bmp");
	SDL_Texture* right = gGame->GetTexture("Assets/right.bmp");
	SDL_Texture* up = gGame->GetTexture("Assets/up.bmp");
	SDL_Texture* bubble = gGame->GetTexture("Assets/bazziBubble.bmp");
	SDL_Texture* tempdie = gGame->GetTexture("Assets/bazziDie.bmp");

	asc->AddAnimTextures("idle", idle);
	asc->AddAnimTextures("down", down);
	asc->AddAnimTextures("left", left);
	asc->AddAnimTextures("right", right);
	asc->AddAnimTextures("up", up);
	asc->AddAnimTextures("bubble", bubble);
	asc->AddAnimTextures("tempdie", tempdie);

	asc->SetAnimTexture(down, 8);
	SetMovingState(Actor::MovingState::EIdle);

	gGame->AddSprite(static_pointer_cast<SpriteComponent>(asc));
	this->AddComponent(asc);
}

void Player::Die()
{
	Actor::Die();
}

void Player::UpdateActor(float deltaTime)
{
	if (GetState() == State::EBubble)
	{
		mDeathTimer += deltaTime;

		if (isBubbleTimeOut())
		{
			mDeathTimer = 0.f;
			SetState(State::ETempDie);
		}

	}
	else if (GetState() == State::ETempDie)
	{
		mDeathTimer += deltaTime;

		if (isDead())
		{
			SetState(State::EDead);
		}
	}


}


void Player::SetBubbleToLive()
{
	mDeathTimer = 0.f;
	SetState(State::EActive);
}