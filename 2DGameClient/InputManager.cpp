#include "stdafx.h"
#include "InputManager.h"
#include "ServerSession.h"
#include "SendTimer.h"

shared_ptr<InputManager> gInputManager = std::make_shared<InputManager>();


InputManager::InputManager()
{
	mForwardKey = SDL_SCANCODE_RIGHT;
	mBackKey = SDL_SCANCODE_LEFT;
	mDownKey = SDL_SCANCODE_DOWN;
	mUpKey = SDL_SCANCODE_UP;
	mSpaceKey = SDL_SCANCODE_SPACE;
	mEscKey = SDL_SCANCODE_ESCAPE;
}


bool InputManager::Init()
{
	mCurrentState.mCurrState = SDL_GetKeyboardState(NULL);

	memset(mCurrentState.mPrevState, 0,
		SDL_NUM_SCANCODES);
	
	return true;
}

void InputManager::PrepareForUpdate()
{
	memcpy(mCurrentState.mPrevState,
		mCurrentState.mCurrState,
		SDL_NUM_SCANCODES);
}

bool KeyboardState::GetKeyValue(SDL_Scancode keyCode) const
{
	return mCurrState[keyCode] == 1;
}

ButtonState KeyboardState::GetKeyState(SDL_Scancode keyCode) const
{
	if (mPrevState[keyCode] == 0)
	{
		if (mCurrState[keyCode] == 0)
		{
			return ENone;
		}
		else
		{
			return EPressed;
		}
	}
	else
	{
		if (mCurrState[keyCode] == 0)
		{
			return EReleased;
		}
		else
		{
			return EHeld;
		}
	}
}


void InputManager::Update()
{
	
	Protocol::Action action = Protocol::Action::ACTION_NONE;

	if (mCurrentState.GetKeyValue(SDL_Scancode(mForwardKey)) == EPressed)
	{
		action = Protocol::Action::ACTION_RIGHT;
	}

	else if (mCurrentState.GetKeyValue(SDL_Scancode(mBackKey)) == EPressed)
	{
		action = Protocol::Action::ACTION_LEFT;
	}

	else if (mCurrentState.GetKeyValue(SDL_Scancode(mUpKey)) == EPressed)
	{
		action = Protocol::Action::ACTION_UP;
	}

	else if (mCurrentState.GetKeyValue(SDL_Scancode(mDownKey)) == EPressed)
	{
		action = Protocol::Action::ACTION_DOWN;
	}
	else if (mCurrentState.GetKeyValue(SDL_Scancode(mSpaceKey)) == EPressed)
	{
		action = Protocol::Action::ACTION_ATTACK;
		mActionList.PushFront(std::make_shared<Action>(action, 1, 1));
		return;
	}
	else
	{
		action = Protocol::Action::ACTION_NONE;
	}


	mActionList.Push(std::make_shared<Action>(action, 1, 1));
}

void InputManager::Send()
{
	if (mActionList.IsEmpty() == false)
	{
		Protocol::C_ACTION actionPkt;

		auto startIdx = mActionList.GetSize() > 3 ? mActionList.GetSize() - 3 - 1 : 0;

		for (auto i = startIdx; i < mActionList.GetSize(); ++i)
		{
			actionPkt.add_playeractions(mActionList[i]->GetAction());
		}

		mActionList.Clear();

		mServerSession->Send(2, actionPkt);
	}
}
