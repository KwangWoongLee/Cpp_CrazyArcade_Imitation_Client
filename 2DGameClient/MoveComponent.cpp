#include "stdafx.h"

MoveComponent::MoveComponent(ActorRef owner, int updateOrder)
	:Component(owner, updateOrder)
	,mForwardSpeed(0.f)
	,mUpwardSpeed(0.f)
	,mMovingSpeed(0.f)
{
}

void MoveComponent::Update(float deltaTime)
{
	if (auto owner = mOwner.lock())
	{
		Vector2 pos = owner->GetPosition();
		auto movingState = owner->GetMovingState();

		switch (movingState)
		{
		case Actor::MovingState::ENone:
			break;
		case Actor::MovingState::EIdle:
			mForwardSpeed = 0;
			mUpwardSpeed = 0;
			break;
		case Actor::MovingState::ELeft:
			mForwardSpeed = -1;
			mUpwardSpeed = 0;
			break;
		case Actor::MovingState::ERight:
			mForwardSpeed = 1;
			mUpwardSpeed = 0;
			break;
		case Actor::MovingState::EUp:
			mUpwardSpeed = -1;
			mForwardSpeed = 0;
			break;
		case Actor::MovingState::EDown:
			mUpwardSpeed = 1;
			mForwardSpeed = 0;
			break;
		case Actor::MovingState::EStop:
			mForwardSpeed = 0;
			mUpwardSpeed = 0;
			break;
		default:
			break;
		}

		if (abs(mForwardSpeed) > 0.001f)
		{
			pos.x += mForwardSpeed * mMovingSpeed * deltaTime;
		}

		if (abs(mUpwardSpeed) > 0.001f)
		{
			pos.y += mUpwardSpeed * mMovingSpeed * deltaTime;
		}

		owner->SetPosition(pos);
	}
}
