#include "stdafx.h"
#include "ServerPacketHandler.h"
#include "Sender.h"

InputComponent::InputComponent(ActorRef owner)
	:MoveComponent(owner)
	, mForwardKey(0)
	, mBackKey(0)
	, mUpKey(0)
	, mDownKey(0)
	, mLastKey(0)
{
	mServerPos = owner->GetPosition();
}

void InputComponent::ProcessInput(const class KeyboardState& keyState)
{
	Protocol::PlayerAction action = Protocol::PlayerAction::PLAYER_ACTION_NONE;

	if (auto owner = mOwner.lock())
	{
		if (keyState.GetKeyState(SDL_Scancode(mForwardKey)) == EReleased ||
			keyState.GetKeyState(SDL_Scancode(mForwardKey)) == ENone ||
			keyState.GetKeyState(SDL_Scancode(mBackKey)) == EReleased ||
			keyState.GetKeyState(SDL_Scancode(mBackKey)) == ENone ||
			keyState.GetKeyState(SDL_Scancode(mUpKey)) == EReleased ||
			keyState.GetKeyState(SDL_Scancode(mUpKey)) == ENone ||
			keyState.GetKeyState(SDL_Scancode(mDownKey)) == EReleased ||
			keyState.GetKeyState(SDL_Scancode(mDownKey)) == ENone			)
		{
			action = Protocol::PlayerAction::PLAYER_ACTION_STOP;
		}

		if (keyState.GetKeyValue(SDL_Scancode(mForwardKey)))
		{
			action = Protocol::PlayerAction::PLAYER_ACTION_RIGHT;
			mServerPos = Vector2(owner->GetPosition().x + 10.f, owner->GetPosition().y);
		}

		if (keyState.GetKeyValue(SDL_Scancode(mBackKey)))
		{
			action = Protocol::PlayerAction::PLAYER_ACTION_LEFT;
			mServerPos = Vector2(owner->GetPosition().x - 10.f, owner->GetPosition().y);
		}

		if (keyState.GetKeyValue(SDL_Scancode(mUpKey)))
		{
			action = Protocol::PlayerAction::PLAYER_ACTION_UP;
			mServerPos = Vector2(owner->GetPosition().x, owner->GetPosition().y - 10.f);
		}

		if (keyState.GetKeyValue(SDL_Scancode(mDownKey)))
		{
			action = Protocol::PlayerAction::PLAYER_ACTION_DOWN;
			mServerPos = Vector2(owner->GetPosition().x, owner->GetPosition().y + 10.f);
		}

		if (action == Protocol::PlayerAction::PLAYER_ACTION_NONE && !keyState.GetKeyValue(SDL_SCANCODE_SPACE))
			return;


		if (mLastAttack < GGame->mTicksCount - 300 && keyState.GetKeyValue(SDL_SCANCODE_SPACE))
		{
			mLastAttack = GGame->mTicksCount;

			Protocol::C_ATTACK attackPkt;
			auto sendBuffer = ServerPacketHandler::MakeSendBuffer(attackPkt);

			GSender->Push(sendBuffer);
		}

		if (action != mLastKey)
		{
			if (mLastServerMove < GGame->mTicksCount - 50)
			{
				Protocol::C_ACTION actionPkt;
				actionPkt.set_playeraction(action);
				auto actor = actionPkt.mutable_actor();
				actor->set_id(owner->GetServerId());
				actor->set_type(Protocol::ActorType::ACTOR_TYPE_PLAYER);
				auto pos = actor->mutable_position();
				pos->set_x(mServerPos.x);
				pos->set_y(mServerPos.y);

				auto sendBuffer = ServerPacketHandler::MakeSendBuffer(actionPkt);

				GSender->Push(sendBuffer);


				mLastServerMove = GGame->mTicksCount;
			}
		}
		else {
			mLastKey = action;
		}
	}

}

void InputComponent::Update(float deltaTime)
{
	mServerTick += deltaTime;
}

//
//void InputComponent::ProcessInput(const class KeyboardState& keyState)
//{
//	if (keyState.GetKeyState(SDL_Scancode(mForwardKey)) == EReleased ||
//		keyState.GetKeyState(SDL_Scancode(mForwardKey)) == ENone ||
//		keyState.GetKeyState(SDL_Scancode(mBackKey)) == EReleased ||
//		keyState.GetKeyState(SDL_Scancode(mBackKey)) == ENone ||
//		keyState.GetKeyState(SDL_Scancode(mUpKey)) == EReleased ||
//		keyState.GetKeyState(SDL_Scancode(mUpKey)) == ENone ||
//		keyState.GetKeyState(SDL_Scancode(mDownKey)) == EReleased ||
//		keyState.GetKeyState(SDL_Scancode(mDownKey)) == ENone
//		)
//	{
//		mOwner->SetMovingState(Actor::MovingState::EStop);
//	}
//
//	float ForWardSpeed = 0.0f;
//	if (keyState.GetKeyValue(SDL_Scancode(mForwardKey)))
//	{
//		ForWardSpeed += GetMovingSpeed();
//		SetUpwardSpeed(0);
//		mOwner->SetMovingState(Actor::MovingState::ERight);
//	}
//
//	if (keyState.GetKeyValue(SDL_Scancode(mBackKey)))
//	{
//		ForWardSpeed -= GetMovingSpeed();
//		SetUpwardSpeed(0);
//		mOwner->SetMovingState(Actor::MovingState::ELeft);
//	}
//	SetForwardSpeed(ForWardSpeed);
//
//
//
//	float UpWardSpeed = 0.0f;
//	if (keyState.GetKeyValue(SDL_Scancode(mUpKey)))
//	{
//		UpWardSpeed -= GetMovingSpeed();
//		SetForwardSpeed(0);
//		mOwner->SetMovingState(Actor::MovingState::EUp);
//	}
//
//	if (keyState.GetKeyValue(SDL_Scancode(mDownKey)))
//	{
//		UpWardSpeed += GetMovingSpeed();
//		SetForwardSpeed(0);
//		mOwner->SetMovingState(Actor::MovingState::EDown);
//	}
//	SetUpwardSpeed(UpWardSpeed);
//
//}
