#pragma once
#include "stdafx.h"

class BG : public Actor
{
public:
	BG(uint64 serverId, string name, Vector2 pos);
	~BG();

	virtual void Init() override;
	virtual void Die() override;

	void UpdateActor(float deltaTime) override;

};

