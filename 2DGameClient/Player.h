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
	Player();
	~Player();

	virtual void Init() override;
	virtual void Die() override;
	virtual void UpdateActor(float deltaTime) override;
	virtual void GetActorInfo(Protocol::PActor* actor) override {
		Actor::GetActorInfo(actor);

		mPlayerType = actor->playertype();
	};
	


	bool isBubbleTimeOut() { return mDeathTimer >= 3.0f; }
	bool isDead() { return mDeathTimer >= 1.f; }
	void SetBubbleToLive();

	float mDeathTimer;
	Protocol::PlayerType mPlayerType = Protocol::PlayerType::PLAYER_TYPE_NONE;
};

