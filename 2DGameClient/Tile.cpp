#include "stdafx.h"

Tile::Tile()
	: mCollider(nullptr)
{
	BlockComponentRef tile = std::make_shared<BlockComponent>(shared_from_this(), 15);
	tile->SetSizeX(8);
	tile->SetSizeY(24);
	//tile->SetTileNumber(tilenum);
	tile->SetTexture(gGame->GetTexture("Assets/Tiles1.bmp"));

	//CollisionComponentRef collider = MakeShared<CollisionComponent>(shared_from_this());
	//collider->SetHalfHeight(32);
	//collider->SetHalfWidth(32);

	//mCollider = collider;

	//gGame->AddTile(this);
}

Tile::~Tile()
{
	//gGame->RemoveTile(this,GetPosition());
}

void Tile::UpdateActor(float deltaTime)
{
	if (GetState() == State::ETempDie)
	{
		mDeathTimer += deltaTime;

		if (isDead())
		{
			SetState(State::EDead);
		}
	}
}
