#include "stdafx.h"
#include "Monster.h"

Monster::Monster()
{
	SetScale(0.4f);
}

Monster::~Monster()
{
}

void Monster::Init()
{
	AnimationComponentRef asc = std::make_shared<AnimationComponent>(shared_from_this(), 200);

	SDL_Texture* idle = gGame->GetTexture("Assets/ggomul_idle.bmp");
	SDL_Texture* down = gGame->GetTexture("Assets/ggomul_down.bmp");
	SDL_Texture* left = gGame->GetTexture("Assets/ggomul_left.bmp");
	SDL_Texture* right = gGame->GetTexture("Assets/ggomul_right.bmp");
	SDL_Texture* up = gGame->GetTexture("Assets/ggomul_up.bmp");
	SDL_Texture* tempdie = gGame->GetTexture("Assets/bazziDie.bmp");

	asc->AddAnimTextures("idle", idle);
	asc->AddAnimTextures("down", down);
	asc->AddAnimTextures("left", left);
	asc->AddAnimTextures("right", right);
	asc->AddAnimTextures("up", up);
	asc->AddAnimTextures("tempdie", tempdie);

	asc->SetAnimTexture(down, 8);

	SetMovingState(MovingState::EIdle);
	gGame->AddSprite(static_pointer_cast<SpriteComponent>(asc));
	this->AddComponent(asc);
}

void Monster::Die()
{
	Actor::Die();
}

void Monster::UpdateActor(float deltaTime)
{
	if (GetState() == State::ETempDie)
	{
		mDeathTimer += deltaTime;

		if (isDead())
		{
			SetState(State::WANT_DIE);
		}
	}

}
