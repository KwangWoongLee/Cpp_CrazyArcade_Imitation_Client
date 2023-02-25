#include "stdafx.h"
#include "BG.h"

BG::BG()
{
}

BG::~BG()
{
}

void BG::Init()
{
	auto bg = std::make_shared<SpriteComponent>(shared_from_this(), 1);
	bg->SetTexture(gGame->GetTexture("Assets/bg.bmp"));

	gGame->AddSprite(bg);
	this->AddComponent(bg);
}

void BG::Die()
{
	Actor::Die();
}

void BG::UpdateActor(float deltaTime)
{

}
