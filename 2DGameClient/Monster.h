#pragma once
#include "stdafx.h"

enum class eMonsterType
{
	MONSTER_TYPE_NONE,
	MONSTER_TYPE_GGOMUL,
};

class Monster : public Actor
{
public:
	Monster();
	~Monster();

	virtual void Init() override;
	virtual void Die() override;
	virtual void UpdateActor(float deltaTime) override;
	virtual void GetActorInfo(Protocol::PActor* actor) override {
		Actor::GetActorInfo(actor);

		mMonsterType = actor->monstertype();
	};

	bool isDead() { return mDeathTimer >= 0.9f; }
	float mDeathTimer;
	Protocol::MonsterType mMonsterType = Protocol::MonsterType::MONSTER_TYPE_NONE;
};

