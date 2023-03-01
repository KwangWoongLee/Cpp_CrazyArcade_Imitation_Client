#pragma once
#include "stdafx.h"

class Bomb;

class Boom : public Actor
{
public:
	enum BoomPosition
	{
		ECenter,
		ELeft,
		ERight,
		EUp,
		EDown
	} EBoomPosition;

	Boom(BoomPosition state, Vector2 pos);
	~Boom();

	virtual void Init() override;
	void Die() override;
	void UpdateActor(float deltaTime) override;


private:
	bool	isTimeToDeath() {return mDeathTimer >= 0.9f;};
	float	mDeathTimer;
};

