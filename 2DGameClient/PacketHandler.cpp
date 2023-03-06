#include "stdafx.h"
#include "PacketHandler.h"
#include "PacketFactory.h"
#include "BG.h"
#include "ServerSession.h"

std::vector<function<void(ServerSessionRef,PacketRef)>> HandleFuncs(UINT16_MAX);


void PacketHandler::Init()
{
	HandleFuncs[0] = &PacketHandler::S_PING;
	HandleFuncs[1] = &PacketHandler::S_ENTER_GAME;
	HandleFuncs[2] = &PacketHandler::S_SPAWN;
	HandleFuncs[3] = &PacketHandler::S_DESPAWN;
	HandleFuncs[4] = &PacketHandler::S_ACTION;
	HandleFuncs[5] = &PacketHandler::S_LEAVE_GAME;
	
}


void PacketHandler::S_PING(ServerSessionRef session, PacketRef packet)
{
	Protocol::C_PONG pongPkt;
	session->Send(0, pongPkt);
}

void PacketHandler::S_ENTER_GAME(ServerSessionRef session, PacketRef packet)
{
	cout << "Server Enter Complete !" << endl;
	auto pkt = static_pointer_cast<Protocol::S_ENTER_GAME>(packet->packet);
	session->mPlayerId = pkt->myplayerid();

	gGame->OnNetwork = true;
	gInputManager->Stop = false;
}

void PacketHandler::S_LEAVE_GAME(ServerSessionRef session, PacketRef packet)
{
	gInputManager->Stop = true;
	session->DisConnect("Game Close");
}

void PacketHandler::S_SPAWN(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_SPAWN>(packet->packet);


	for (auto actor : pkt->actors())
	{
		cout << actor.id() << " 스폰 !" << endl;

		auto type = actor.type();

		switch (type)
		{
		case Protocol::ACTOR_TYPE_NONE:
			break;
		case Protocol::ACTOR_TYPE_PLAYER:
		{
			auto p = std::make_shared<Player>();
			p->GetActorInfo(&actor);

			bool myPlayer = false;
			if (p->GetServerId() == session->mPlayerId)
			{
				session->mPlayer = p;
			}

			p->Init();



			gGame->AddActor(p);
		}
		break;
		case Protocol::ACTOR_TYPE_BLOCK:
		{
			auto b = std::make_shared<Block>();
			b->GetActorInfo(&actor);
			b->Init();

			gGame->AddActor(b);
		}
		break;
		case Protocol::ACTOR_TYPE_BOMB:
		{
			auto b = std::make_shared<Bomb>();
			b->GetActorInfo(&actor);
			b->Init();

			gGame->AddActor(b);
		}
		break;

		case Protocol::ACTOR_TYPE_BG:
		{
			auto b = std::make_shared<BG>();
			b->GetActorInfo(&actor);
			b->Init();

			gGame->AddActor(b);
		}
		break;
		default:
			break;
		}
	}
	
}

void PacketHandler::S_DESPAWN(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_DESPAWN>(packet->packet);

	for (auto actor : pkt->actors())
	{
		auto id = actor.id();
		cout << "디스폰 " << id << " !" << endl;
		auto actorRef = gGame->FindActor(id);
		if (actorRef->mType == Protocol::ACTOR_TYPE_PLAYER)
		{
			actorRef->SetState(State::ETempDie);
		}
		else
		{
			actorRef->SetState(State::WANT_DIE);
		}
	}
}

void PacketHandler::S_ACTION(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_ACTION>(packet->packet);

	auto tickCount = pkt->tickcount();
	auto id = pkt->actorid();
	auto action = pkt->playeraction();

	auto actorRef = gGame->FindActor(id);
	if (actorRef == nullptr) return;

	if (actorRef->mType == Protocol::ACTOR_TYPE_PLAYER)
	{
		auto player = static_pointer_cast<Player>(actorRef);

		if (action == Protocol::ACTION_TEMP_DIE)
		{
			player->SetState(State::EBubble);
			if (session->mPlayerId == id)
				gInputManager->Stop = true;

			return;
		}
		else if (action == Protocol::ACTION_RESURRECT)
		{
			if (session->mPlayerId == id)
				gInputManager->Stop = false;

			player->SetBubbleToLive();
			return;
		}
	}
	
	

	actorRef->MoveNextPosition(action);
}