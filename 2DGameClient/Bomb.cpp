#include "stdafx.h"

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

void Bomb::UpdateActor(float deltaTime)
{
}

void Bomb::Die()
{
	Actor::Die();

	auto boomCenter = MakeShared<Boom>(Boom::ECenter, GetPosition());
	auto boomRight = MakeShared<Boom>(Boom::ERight, Vector2(GetPosition().x + 32, GetPosition().y));
	auto boomLeft = MakeShared<Boom>(Boom::ELeft, Vector2(GetPosition().x - 32, GetPosition().y));
	auto boomUp = MakeShared<Boom>(Boom::EUp, Vector2(GetPosition().x, GetPosition().y - 32));
	auto boomDown = MakeShared<Boom>(Boom::EDown, Vector2(GetPosition().x, GetPosition().y + 32));

	boomCenter->Init();
	boomRight->Init();
	boomLeft->Init();
	boomUp->Init();
	boomDown->Init();
}

void Bomb::Init()
{
	auto anim = std::make_shared<AnimationComponent>(shared_from_this(), 150);
	SDL_Texture* bomb = gGame->GetTexture("Assets/bomb.bmp");

	anim->SetAnimTexture(bomb, 4);
	gGame->AddSprite(static_pointer_cast<SpriteComponent>(anim));
	AddComponent(anim);
}

