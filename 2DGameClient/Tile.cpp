#include "stdafx.h"

Tile::Tile(uint64 serverId, int tilenum, Vector2 pos)
	: Actor(serverId, "", pos)
	, mCollider(nullptr)
{
	BlockComponentRef tile = MakeShared<BlockComponent>(shared_from_this(), 15);
	tile->SetSizeX(8);
	tile->SetSizeY(24);
	//tile->SetTileNumber(tilenum);
	tile->SetTexture(GGame->GetTexture("Assets/Tiles1.bmp"));

	//CollisionComponentRef collider = MakeShared<CollisionComponent>(shared_from_this());
	//collider->SetHalfHeight(32);
	//collider->SetHalfWidth(32);

	//mCollider = collider;

	//GGame->AddTile(this);
}

Tile::~Tile()
{
	//GGame->RemoveTile(this,GetPosition());
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
