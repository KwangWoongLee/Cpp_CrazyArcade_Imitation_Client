#pragma once
#include "stdafx.h"

class Block : public Actor
{
public:
	Block(uint64 serverId, string name, Protocol::BlockType blockType, Vector2 pos);
	~Block();

	virtual void Init() override;
	virtual void Die() override;

	void UpdateActor(float deltaTime) override;


private:
	Protocol::BlockType mBlockType = Protocol::BlockType::BLOCK_TYPE_NONE;
};

