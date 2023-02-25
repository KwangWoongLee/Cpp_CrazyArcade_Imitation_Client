#include "stdafx.h"

Boom::Boom(BoomPosition state)
	: mDeathTimer(0.f)
	, EBoomPosition(state)
{
	
}

Boom::~Boom()
{
	//gGame->RemoveBoom(this);
}

void Boom::Init()
{
	AnimationComponentRef anim = std::make_shared<AnimationComponent>(shared_from_this(), 150);
	SDL_Texture* boomCenter = gGame->GetTexture("Assets/boom_center.bmp");
	SDL_Texture* boomLeft = gGame->GetTexture("Assets/boom_left.bmp");
	SDL_Texture* boomRight = gGame->GetTexture("Assets/boom_right.bmp");
	SDL_Texture* boomUp = gGame->GetTexture("Assets/boom_up.bmp");
	SDL_Texture* boomDown = gGame->GetTexture("Assets/boom_down.bmp");

	switch (EBoomPosition)
	{
	case ECenter:
		anim->SetAnimTexture(boomCenter, 14);
		break;

	case ELeft:
		anim->SetAnimTexture(boomLeft, 9);
		break;

	case ERight:
		anim->SetAnimTexture(boomRight, 9);
		break;

	case EUp:
		anim->SetAnimTexture(boomUp, 9);
		break;

	case EDown:
		anim->SetAnimTexture(boomDown, 9);
		break;
	};

	gGame->AddSprite(static_pointer_cast<SpriteComponent>(anim));
	this->AddComponent(anim);

	gGame->AddActor(shared_from_this());
}

void Boom::Die()
{
	;
}

void Boom::UpdateActor(float deltaTime)
{

	//Boom Actor 의 자동 죽음처리
	mDeathTimer += deltaTime;
	if (isTimeToDeath())
		WantDie();
}

