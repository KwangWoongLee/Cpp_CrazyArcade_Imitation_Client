#include "stdafx.h"
#include "BG.h"

BG::BG(uint64 serverId, string name, Vector2 pos)
	:Actor(serverId, name, pos)
{
}

BG::~BG()
{
}

void BG::Init()
{
	auto bg = MakeShared<SpriteComponent>(shared_from_this(), 1);
	bg->SetTexture(GGame->GetTexture("Assets/bg.bmp"));

	GGame->AddSprite(bg);
	this->AddComponent(bg);
}

void BG::Die()
{
	Actor::Die();
}

void BG::UpdateActor(float deltaTime)
{

}
