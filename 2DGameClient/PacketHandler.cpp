#include "stdafx.h"
#include "PacketHandler.h"
#include "PacketFactory.h"
#include "BG.h"
#include "ServerSession.h"
#include "SendTimer.h"

std::vector<function<void(ServerSessionRef,PacketRef)>> HandleFuncs(UINT16_MAX);


void PacketHandler::Init()
{
	HandleFuncs[0] = &PacketHandler::S_PING;
	HandleFuncs[1] = &PacketHandler::S_ENTER_GAME;
	HandleFuncs[2] = &PacketHandler::S_SPAWN;
	HandleFuncs[3] = &PacketHandler::S_DESPAWN;
	HandleFuncs[4] = &PacketHandler::S_ACTION;
	
}


void PacketHandler::S_PING(ServerSessionRef session, PacketRef packet)
{
	//cout << "PING" << endl;

	Protocol::C_PONG pongPkt;
	session->Send(0, pongPkt);
	//std::shared_ptr<google::protobuf::MessageLite> sharedPacket = std::make_shared<Protocol::C_PONG>(pongPkt);
	//gSendTimer->DoAsync(&SendTimer::Push, std::pair{ static_cast<uint16>(0), sharedPacket });
}

void PacketHandler::S_ENTER_GAME(ServerSessionRef session, PacketRef packet)
{
	cout << "Enter From Server" << endl;
	auto pkt = static_pointer_cast<Protocol::S_ENTER_GAME>(packet->packet);
	session->mPlayerId = pkt->myplayerid();

	for (auto actor : pkt->exisitingactors())
	{
		auto type = actor.type();

		switch (type)
		{
		case Protocol::ACTOR_TYPE_NONE:
			break;
		case Protocol::ACTOR_TYPE_PLAYER:
		{
			auto p = std::make_shared<Player>();
			p->GetActorInfo(&actor);
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
			//auto b = MakeShared<Bomb>(id, name, Vector2(pos.x(), pos.y()));
			//b->Init();

			//gGame->AddActor(b);
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


	gGame->OnNetwork = true;
}

void PacketHandler::S_SPAWN(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_SPAWN>(packet->packet);


	for (auto actor : pkt->actors())
	{
		cout << actor.id() << " Á¢¼Ó" << endl;

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
			//auto b = MakeShared<Bomb>(id, name, Vector2(pos.x(), pos.y()));
			//b->Init();

			//gGame->AddActor(b);
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
		cout << "DESPAWN " << id << endl;
		auto actorRef = gGame->FindActor(id);
		gGame->RemoveActor(actorRef);

		if (session->mPlayerId == id)
			session->mPlayer = nullptr;
	}
}

void PacketHandler::S_ACTION(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_ACTION>(packet->packet);

	auto tickCount = pkt->tickcount();
	auto id = pkt->actorid();
	auto action = pkt->playeraction();

	auto actorRef = gGame->FindActor(id);
	actorRef->MoveNextPosition(action);
}