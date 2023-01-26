#pragma once
#include "stdafx.h"

class InputComponent : public MoveComponent
{
public:
	InputComponent(ActorRef owner);

	void ProcessInput(const class KeyboardState& keyState) override;

	virtual void Update(float deltaTime) override;


	int GetForwardKey() const { return mForwardKey; }
	void SetForwardKey(int key) { mForwardKey = key; }

	int GetBackKey() const { return mBackKey; }
	void SetBackKey(int key) { mBackKey = key; }

	int GetUpKey() const { return mUpKey; }
	void SetUpKey(int key) { mUpKey = key; }

	int GetDownKey() const { return mDownKey; }
	void SetDownKey(int key) { mDownKey = key; }



	float	mLastServerMove{};
	float	mLastAttack{};

	uint64	mServerTick{};
	Vector2 mServerPos{};
private:
	uint8_t	mForwardKey;
	uint8_t	mBackKey;
	uint8_t	mUpKey;
	uint8_t	mDownKey;

	uint8_t mLastKey{};
};

