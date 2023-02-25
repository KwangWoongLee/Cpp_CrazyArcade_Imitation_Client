#include "stdafx.h"

Bomb::Bomb()
	: bFirstContact(true)
{
}

Bomb::~Bomb()
{

}

void Bomb::UpdateActor(float deltaTime)
{
}

void Bomb::Die()
{/*

	BoomRef boomCenter = std::make_shared<Boom>(Boom::ECenter, GetPosition());
	boomCenter->SetPosition(GetPosition());
	boomCenter->Init();

	BoomRef boomRight = std::make_shared<Boom>(Boom::ERight, Vector2(GetPosition().x + 32, GetPosition().y));
	boomRight->Init();

	BoomRef boomLeft = std::make_shared<Boom>(Boom::ELeft, Vector2(GetPosition().x - 32, GetPosition().y));
	boomLeft->Init();

	BoomRef boomUp = std::make_shared<Boom>(Boom::EUp, Vector2(GetPosition().x, GetPosition().y - 32));
	boomUp->Init();

	BoomRef boomDown = std::make_shared<Boom>(Boom::EDown, Vector2(GetPosition().x, GetPosition().y + 32));
	boomDown->Init();

	Protocol::C_EXPLODE_BOMB explodePkt;
	explodePkt.set_bombid(GetServerId());*/

	//auto sendBuffer = ServerPacketHandler::MakeSendBuffer(explodePkt);

	//GSender->Push(sendBuffer);

	Actor::Die();
}

void Bomb::Init()
{
	auto anim = std::make_shared<AnimationComponent>(shared_from_this(), 150);
	SDL_Texture* bomb = gGame->GetTexture("Assets/bomb.bmp");

	anim->SetAnimTexture(bomb, 4);
	gGame->AddSprite(static_pointer_cast<SpriteComponent>(anim));
	this->AddComponent(anim);
}

