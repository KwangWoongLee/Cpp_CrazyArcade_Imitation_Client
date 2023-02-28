#include "stdafx.h"
#include "ServerPacketHandler.h"
#include "ServerSession.h"
#include "World.h"
#include "BG.h"
#include "Protocol.pb.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

// 직접 컨텐츠 작업자

bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
{
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	// TODO : Log
	return false;
}

bool Handle_S_ENTER_GAME(PacketSessionRef& session, Protocol::S_ENTER_GAME& pkt)
{
	ServerSessionRef serverSession = static_pointer_cast<ServerSession>(session);

	// TODO
	if (pkt.success() == false)
	{
		//입장에러 처리
		return true;
	}

	serverSession->mPlayerId = pkt.playerid();
	return true;
}

bool Handle_S_LEAVE_GAME(PacketSessionRef& session, Protocol::S_LEAVE_GAME& pkt)
{
	return true;
}

bool Handle_S_ACTION(PacketSessionRef& session, Protocol::S_ACTION& pkt)
{
	ServerSessionRef serverSession = static_pointer_cast<ServerSession>(session);

	if (pkt.ignores_size() != 0)
	{
		auto ignores = pkt.ignores();
		if (std::find(ignores.begin(), ignores.end(), serverSession->mPlayer->GetServerId()) != ignores.end())
			return true;
	}

	auto tickCount = pkt.tickcount();
	//serverSession->mPlayer->SetServerTick(tickCount);
	auto actor = pkt.actor();
	auto type = actor.type();
	auto id = actor.id();

	ActorRef findedActor = GGame->FindActor(id);

	if (type == Protocol::ACTOR_TYPE_PLAYER)
	{
		if (findedActor == nullptr)
			return true;

		auto pos = actor.position();
		auto action = pkt.playeraction();

		Actor::MovingState state;
		switch (action)
		{
		case Protocol::PLAYER_ACTION_NONE:
			state = Actor::MovingState::ENone;
			break;
		case Protocol::PLAYER_ACTION_UP:
			state = Actor::MovingState::EUp;
			break;
		case Protocol::PLAYER_ACTION_DOWN:
			state = Actor::MovingState::EDown;
			break;
		case Protocol::PLAYER_ACTION_LEFT:
			state = Actor::MovingState::ELeft;
			break;
		case Protocol::PLAYER_ACTION_RIGHT:
			state = Actor::MovingState::ERight;
			break;
		case Protocol::PLAYER_ACTION_STOP:
			state = Actor::MovingState::EStop;
			break;
		default:
			break;
		
		}


		findedActor->SetMovingState(state);
		findedActor->SetPosition(Vector2(pos.x(), pos.y()));

		std::cout << "플레이어 (" << id << ")가 이동" << std::endl;
		
	}

	return true;
}

bool Handle_S_SPAWN(PacketSessionRef& session, Protocol::S_SPAWN& pkt)
{
	ServerSessionRef serverSession = static_pointer_cast<ServerSession>(session);

	auto size = pkt.actor_size();
	if (size > 0)
	{
		for (auto actor : pkt.actor())
		{
			auto id = actor.id();
			auto name = actor.name();
			auto type = actor.type();
			auto pos = actor.position();

			switch (type)
			{
			case Protocol::ACTOR_TYPE_NONE:
				break;
			case Protocol::ACTOR_TYPE_PLAYER:
			{
				if (!actor.has_playertype())
					break;

				auto playerType = actor.playertype();

				bool myPlayer = false;
				if (id == serverSession->mPlayerId)
				{
					myPlayer = true;
				}


				auto p = MakeShared<Player>(id, name, playerType, Vector2(pos.x(), pos.y()), myPlayer);
				p->Init();

				if(myPlayer)
					serverSession->mPlayer = p;

				GGame->AddActor(p);
			}
				break;
			case Protocol::ACTOR_TYPE_BLOCK:
			{
				if (!actor.has_blocktype())
					break;

				auto blockType = actor.blocktype();

				auto b = MakeShared<Block>(id, name, blockType, Vector2(pos.x(), pos.y()));
				b->Init();

				GGame->AddActor(b);
			}
				break;
			case Protocol::ACTOR_TYPE_BOMB:
			{
				auto b = MakeShared<Bomb>(id, name,  Vector2(pos.x(), pos.y()));
				b->Init();

				GGame->AddActor(b);
			}
			break;

			case Protocol::ACTOR_TYPE_BG:
			{
				auto b = MakeShared<BG>(id, "", Vector2(pos.x(), pos.y()));
				b->Init();

				GGame->AddActor(b);
			}
			break;
			default:
				break;
			}
		}

	}
	return true;
}

bool Handle_S_DESPAWN(PacketSessionRef& session, Protocol::S_DESPAWN& pkt)
{
	ServerSessionRef serverSession = static_pointer_cast<ServerSession>(session);

	if (pkt.actor_size() > 0)
	{
		for (auto actor : pkt.actor())
		{
			auto id = actor.id();

			ActorRef findedActor = GGame->FindActor(id);
			if (findedActor)
			{
				findedActor->WantDie();

				if (serverSession->mPlayerId == id)
				{
					serverSession->mPlayer = nullptr;
					serverSession->mPlayerId = 0;
				}
			}
		}
	}
	
	return true;
}

bool Handle_S_PING(PacketSessionRef& session, Protocol::S_PING& pkt)
{
	Protocol::C_PONG pongPkt;
	session->Send(ServerPacketHandler::MakeSendBuffer(pongPkt));

	std::cout << "PING" << std::endl;
	return true;
}
