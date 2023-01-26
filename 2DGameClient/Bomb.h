#pragma once
#include "stdafx.h"

class Bomb : public Actor
{
public:
	Bomb(uint64 serverId, string name, Vector2 pos);
	~Bomb();
	
	virtual void Init() override;

	void UpdateActor(float deltaTime) override;
	void Die() override;
	
	CollisionComponentRef GetCollider() const { return mCollider; }


private:
	bool	bFirstContact;

	CollisionComponentRef mCollider;
};

