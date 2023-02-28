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
	SetMovingState(Actor::MovingState::EIdle);
	SpriteComponentRef sprite = std::make_shared<SpriteComponent>(shared_from_this(), 15);

	gGame->AddSprite(sprite);
	this->AddComponent(static_pointer_cast<Component>(sprite));
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
