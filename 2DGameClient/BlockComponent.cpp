#include "stdafx.h"

BlockComponent::BlockComponent(ActorRef owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mSizeX(0)
	, mSizeY(0)
	, mTileNum(0)
{
	SetTileSizeX(32);
	SetTileSizeY(32);
}

BlockComponent::~BlockComponent()
{
}

void BlockComponent::Draw(SDL_Renderer* renderer, int gameScale)
{
	if (auto owner = mOwner.lock())
	{
		if (mTexture)
		{
			SDL_Rect src;
			src.w = static_cast<int>(mTileSizeX );
			src.h = static_cast<int>(mTileSizeY);
			src.x = static_cast<int>((int)mBlockType % mSizeX * mTileSizeX);
			src.y = static_cast<int>((int)mBlockType / mSizeY * mTileSizeY);

			//소유 actor의 정보에 따라 texture 배치

			SDL_Rect dsc;
			dsc.w = static_cast<int>(mTileSizeX) * gameScale;
			dsc.h = static_cast<int>(mTileSizeY) * gameScale;
			dsc.x = static_cast<int>(owner->GetPosition().x - dsc.w / 2) * gameScale;
			dsc.y = static_cast<int>(owner->GetPosition().y - dsc.h / 2) * gameScale;

			SDL_RenderCopy(renderer,
				mTexture,
				&src,
				&dsc);
		}
	}
}
