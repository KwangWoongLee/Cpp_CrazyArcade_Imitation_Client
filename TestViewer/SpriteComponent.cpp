#include "stdafx.h"

SpriteComponent::SpriteComponent(ActorRef owner, int drawOrder)
	:Component(owner)
	,mDrawOrder(drawOrder)
	,mTextureHeight(0)
	,mTextureWidth(0)
{
}

SpriteComponent::~SpriteComponent()
{
	//gGame->RemoveSprite(static_pointer_cast<SpriteComponent>(shared_from_this()));
}

void SpriteComponent::Draw(SDL_Renderer* renderer, int gameScale)
{

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	if (auto owner = mOwner.lock()) {
		//소유 actor의 정보에 따라 texture 배치
		SDL_Rect r;
		r.w = static_cast<int>(mTextureWidth * owner->GetScale()) * 5;
		r.h = static_cast<int>(mTextureHeight * owner->GetScale()) * 5;
		r.x = static_cast<int>(owner->GetPosition().x - r.w / 2) * gameScale;
		r.y = static_cast<int>(owner->GetPosition().y - r.h / 2) * gameScale;

		SDL_RenderDrawRect(renderer, &r);
	}
}