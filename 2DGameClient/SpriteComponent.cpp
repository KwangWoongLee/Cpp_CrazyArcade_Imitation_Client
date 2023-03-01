#include "stdafx.h"

SpriteComponent::SpriteComponent(ActorRef owner, int drawOrder)
	:Component(owner)
	,mTexture(nullptr)
	,mDrawOrder(drawOrder)
	,mTextureHeight(0)
	,mTextureWidth(0)
{
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::DrawRect(SDL_Renderer* renderer, int gameScale)
{
	if (auto owner = mOwner.lock()) {
		SDL_Rect r;
		r.w = static_cast<int>(mTextureWidth * owner->GetScale()) * gameScale;
		r.h = static_cast<int>(mTextureHeight * owner->GetScale()) * gameScale;
		r.x = static_cast<int>(owner->GetPosition().x - r.w / 2) * gameScale;
		r.y = static_cast<int>(owner->GetPosition().y - r.h / 2) * gameScale;


		SDL_RenderDrawRect(renderer,
			&r);
	}
}

void SpriteComponent::Draw(SDL_Renderer* renderer, int gameScale)
{
	if (auto owner = mOwner.lock()) {
		if (mTexture)
		{

			//���� actor�� ������ ���� texture ��ġ
			SDL_Rect r;
			r.w = static_cast<int>(mTextureWidth * owner->GetScale()) * gameScale;
			r.h = static_cast<int>(mTextureHeight * owner->GetScale()) * gameScale;
			r.x = static_cast<int>(owner->GetPosition().x - r.w / 2) * gameScale;
			r.y = static_cast<int>(owner->GetPosition().y - r.h / 2) * gameScale;


			SDL_RenderCopy(renderer,
				mTexture,
				nullptr,
				&r);
		}
	}
}


void SpriteComponent::SetTexture(SDL_Texture* texture)
{
	mTexture = texture;

	//�ش� texture�� width�� height ������ ����
	SDL_QueryTexture(texture, nullptr, nullptr, &mTextureWidth, &mTextureHeight);
}
