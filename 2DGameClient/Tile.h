#pragma once
#include "stdafx.h"

class Tile : public Actor
{
public:

	enum class TileType
	{
		ENone,
		EBlock,
		EBush
	};

	Tile();
	~Tile();

	void UpdateActor(float deltaTime) override;
	virtual void GetActorInfo(Protocol::PActor* actor) override {
		Actor::GetActorInfo(actor);

	};

	TileType GetTileType() const { return mType; }
	void SetTileType(TileType type) { mType = type; }

	CollisionComponentRef GetCollider() const { return mCollider; }

	bool isDead() { return mDeathTimer >= 0.2f; }

private:
	CollisionComponentRef mCollider;
	TileType mType;

	float mDeathTimer;
};

