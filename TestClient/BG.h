#pragma once
#include "stdafx.h"

class BG : public Actor
{
public:
	BG();
	~BG();

	virtual void Init() override;
	virtual void Die() override;

	void UpdateActor(float deltaTime) override;
};

