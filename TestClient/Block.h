#pragma once
#include "stdafx.h"

class Block : public Actor
{
public:
	Block();
	~Block();

	virtual void Init() override;
	virtual void Die() override;

	void UpdateActor(float deltaTime) override;
	virtual void GetActorInfo(Protocol::PActor* actor) override {
		Actor::GetActorInfo(actor);

		mBlockType = actor->blocktype();
	};

private:
	Protocol::BlockType mBlockType = Protocol::BlockType::BLOCK_TYPE_NONE;
};

