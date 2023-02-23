#pragma once
#include "Action.h"

enum ButtonState
{
	ENone,
	EPressed,
	EReleased,
	EHeld
};


class KeyboardState
{
public:
	friend class InputManager;
	bool GetKeyValue(SDL_Scancode keyCode) const;
	ButtonState GetKeyState(SDL_Scancode keyCode) const;
private:
	const Uint8* mCurrState;
	Uint8 mPrevState[SDL_NUM_SCANCODES];
};


class InputManager
{
public:
	InputManager();
	virtual ~InputManager() {
		mActionList.Clear();
		mServerSession = nullptr;
	};
	void SetSession(ServerSessionRef session) { mServerSession = session; }

	bool Init();
	void PrepareForUpdate();

	const KeyboardState& GetState()	const { return mCurrentState; }
	ActionList& GetActionList() { return mActionList; }

	ActionRef GetPendingMove() 
	{ 
		return mPendingAction; 
	}


	void				Update();
	void				Send();
	
private:
	ServerSessionRef mServerSession;

	KeyboardState	mCurrentState;


	ActionList		mActionList;
	float			mNextTimeToSampleInput;
	ActionRef mPendingAction;



	uint8_t	mForwardKey;
	uint8_t	mBackKey;
	uint8_t	mUpKey;
	uint8_t	mDownKey;
};

extern shared_ptr<InputManager> gInputManager;