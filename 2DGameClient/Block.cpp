#include "stdafx.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::Init()
{
	auto tile = std::make_shared<BlockComponent>(shared_from_this(), 15);
	tile->SetSizeX(8);
	tile->SetSizeY(24);
	tile->SetBlockType(mBlockType);
	tile->SetTexture(gGame->GetTexture("Assets/Tiles.png"));


	gGame->AddSprite(static_pointer_cast<SpriteComponent>(tile));
	AddComponent(tile);
}

void Block::Die()
{
	Actor::Die();
}

void Block::UpdateActor(float deltaTime)
{

}
