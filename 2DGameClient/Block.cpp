#include "stdafx.h"

Block::Block(uint64 serverId, string name, Protocol::BlockType blockType, Vector2 pos)
	:Actor(serverId, name, pos)
{
	mBlockType = blockType;
}

Block::~Block()
{
}

void Block::Init()
{
	auto tile = MakeShared<BlockComponent>(shared_from_this(), 15);
	tile->SetSizeX(8);
	tile->SetSizeY(24);
	tile->SetBlockType(mBlockType);
	tile->SetTexture(GGame->GetTexture("Assets/Tiles.png"));


	GGame->AddSprite(static_pointer_cast<SpriteComponent>(tile));
	this->AddComponent(tile);
}

void Block::Die()
{
	Actor::Die();
}

void Block::UpdateActor(float deltaTime)
{

}
