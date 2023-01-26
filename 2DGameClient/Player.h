#pragma once
#include "stdafx.h"

enum class ePlayerType
{
	PLAYER_TYPE_NONE,
	PLAYER_TYPE_BAZZI,
	PLAYER_TYPE_DAO,
};

class Player : public Actor
{
public:
	Player(uint64 serverId, string name, Protocol::PlayerType type, Vector2 pos, bool myPlayer);
	~Player();

	virtual void Init() override;

	virtual void Die() override;

	virtual void UpdateActor(float deltaTime) override;
	
	void ActorInput(const class KeyboardState& keyState) override;

	void SetBubbleToLive();

	bool isBubbleTimeOut() { return mDeathTimer >= 3.0f; }

	bool isDead() { return mDeathTimer >= 1.1f; }

	InputComponentRef mInputComponent = nullptr;
	float mDeathTimer;
	Protocol::PlayerType mPlayerType = Protocol::PlayerType::PLAYER_TYPE_NONE;
	bool mMyPlayer = false;
};

