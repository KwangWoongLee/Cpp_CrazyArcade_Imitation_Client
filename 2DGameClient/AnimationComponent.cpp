#include "stdafx.h"

AnimationComponent::AnimationComponent(ActorRef owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mCurrFrame(0.0f)
	, mAnimFPS(10.0f)
	, mFrameX(1)
{
}

void AnimationComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	if (auto owner = mOwner.lock())
	{
		if (owner->GetMovingState() == MovingState::EIdle)
		{
			mAnimTexture = mAnimTextures.find("idle")->second;
			mFrameX = 1;
		}
		else if (owner->GetMovingState() == MovingState::EDown)
		{
			mAnimTexture = mAnimTextures.find("down")->second;
			mFrameX = 8;
		}
		else if (owner->GetMovingState() == MovingState::EUp)
		{
			mAnimTexture = mAnimTextures.find("up")->second;
			mFrameX = 8;
		}
		else if (owner->GetMovingState() == MovingState::ERight)
		{
			mAnimTexture = mAnimTextures.find("right")->second;
			mFrameX = 6;
		}
		else if (owner->GetMovingState() == MovingState::ELeft)
		{
			mAnimTexture = mAnimTextures.find("left")->second;
			mFrameX = 6;
		}

		if (owner->GetState() == State::EBubble)
		{
			mAnimTexture = mAnimTextures.find("bubble")->second;
			mFrameX = 16;
		}
		else if (owner->GetState() == State::ETempDie)
		{
			mAnimTexture = mAnimTextures.find("tempdie")->second;
			mFrameX = 13;
		}

		if (owner->GetMovingState() == MovingState::EStop && owner->GetState() == State::EActive)
		{
			mCurrFrame = 0.f;
		}
		else
		{
			mCurrFrame += mAnimFPS * deltaTime;
		}

		//모든 texture animation이 끝나면 처음 animation으로 변경
		while (mCurrFrame >= mFrameX)
		{
			mCurrFrame -= mFrameX;
		}

		// mCurrFrame에 맞는 texture 적용
		SetTexture(mAnimTexture);
	}
	
}

void AnimationComponent::Draw(SDL_Renderer* renderer, int gameScale)
{
	if (auto owner = mOwner.lock())
	{
		if (mTexture)
		{
			SDL_Rect src;
			src.w = static_cast<int>(mTextureWidth / mFrameX);
			src.h = static_cast<int>(mTextureHeight);
			src.x = static_cast<int>(mTextureWidth / mFrameX * static_cast<int>(mCurrFrame));
			src.y = static_cast<int>(0);

			//소유 actor의 정보에 따라 texture 배치
			SDL_Rect dsc;
			dsc.w = static_cast<int>(mTextureWidth / mFrameX * owner->GetScale()) * gameScale;
			dsc.h = static_cast<int>(mTextureHeight * owner->GetScale()) * gameScale;
			//dsc.x = static_cast<int>(owner->GetPosition().x - dsc.w / 2) * gameScale + mTextureWidth / mFrameX;
			//dsc.y = static_cast<int>(owner->GetPosition().y - dsc.h / 2) * gameScale + mTextureHeight;
			//dsc.w = static_cast<int>(1) * gameScale;
			//dsc.h = static_cast<int>(1) * gameScale;
			dsc.x = static_cast<int>(owner->GetPosition().x - dsc.w / 2) * gameScale;
			dsc.y = static_cast<int>(owner->GetPosition().y - dsc.h / 2) * gameScale;

			SDL_RenderCopy(renderer,
				mTexture,
				&src,
				&dsc);
		}
	}
}

void AnimationComponent::SetAnimTexture(SDL_Texture* texture, int frameX)
{
	mAnimTexture = texture;

	mFrameX = frameX;

	mCurrFrame = 0.0f;

	
	SetTexture(mAnimTexture);
}

void AnimationComponent::AddAnimTextures(std::string strTexture, SDL_Texture* animTexture)
{
	mAnimTextures.insert(std::pair<std::string, SDL_Texture*>(strTexture, animTexture));
}
