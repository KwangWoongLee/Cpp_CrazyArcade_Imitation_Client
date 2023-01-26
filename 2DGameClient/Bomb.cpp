#include "stdafx.h"
#include "Sender.h"
#include "ServerPacketHandler.h"

Bomb::Bomb(uint64 serverId, string name, Vector2 pos)
	: Actor(serverId, name, pos)
	, bFirstContact(true)
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

	BoomRef boomCenter = MakeShared<Boom>(Boom::ECenter, GetPosition());
	boomCenter->SetPosition(GetPosition());
	boomCenter->Init();

	BoomRef boomRight = MakeShared<Boom>(Boom::ERight, Vector2(GetPosition().x + 32, GetPosition().y));
	boomRight->Init();

	BoomRef boomLeft = MakeShared<Boom>(Boom::ELeft, Vector2(GetPosition().x - 32, GetPosition().y));
	boomLeft->Init();

	BoomRef boomUp = MakeShared<Boom>(Boom::EUp, Vector2(GetPosition().x, GetPosition().y - 32));
	boomUp->Init();

	BoomRef boomDown = MakeShared<Boom>(Boom::EDown, Vector2(GetPosition().x, GetPosition().y + 32));
	boomDown->Init();

	Protocol::C_EXPLODE_BOMB explodePkt;
	explodePkt.set_bombid(GetServerId());

	auto sendBuffer = ServerPacketHandler::MakeSendBuffer(explodePkt);

	GSender->Push(sendBuffer);

	Actor::Die();
}

void Bomb::Init()
{
	auto anim = MakeShared<AnimationComponent>(shared_from_this(), 150);
	SDL_Texture* bomb = GGame->GetTexture("Assets/bomb.bmp");

	anim->SetAnimTexture(bomb, 4);
	GGame->AddSprite(static_pointer_cast<SpriteComponent>(anim));
	this->AddComponent(anim);
}

