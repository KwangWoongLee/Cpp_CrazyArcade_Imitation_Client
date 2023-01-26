#pragma once
#include "stdafx.h"

class BlockComponent : public SpriteComponent
{
public:
	BlockComponent(ActorRef owner, int drawOrder);

	void Draw(SDL_Renderer* renderer, int gameScale = 1) override;

	

	void SetSizeX(int x) { mSizeX = x; }
	void SetSizeY(int y) { mSizeY = y; }
	void SetTileSizeX(int x) { mTileSizeX = x; }
	void SetTileSizeY(int y) { mTileSizeY = y; }
	void SetBlockType(Protocol::BlockType blockType) { mBlockType = blockType; }
private:
	int mSizeX;
	int mSizeY;
	int mTileSizeX;
	int mTileSizeY;
	int mTileNum;
	Protocol::BlockType mBlockType = Protocol::BLOCK_TYPE_NONE;
};

