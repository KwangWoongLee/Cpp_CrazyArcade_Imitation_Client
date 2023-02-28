#include "stdafx.h"
#include "PacketHandler.h"
#include "PacketFactory.h"
#include "ServerSession.h"

std::vector<function<void(ServerSessionRef, PacketRef)>> HandleFuncs(UINT16_MAX);


void PacketHandler::Init()
{
	HandleFuncs[1] = &PacketHandler::S_ENTER_GAME;
}

void PacketHandler::S_ENTER_GAME(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_ENTER_GAME>(packet->packet);

	std::set<uint64> nowActors;
	std::map<uint64, Protocol::PActor> tmpPActors;

	for (auto actor : pkt->exisitingactors())
	{
		nowActors.insert(actor.id());
		tmpPActors[actor.id()] = actor;
	}


	std::set<uint64> newActorSet;
	std::set_difference(nowActors.begin(), nowActors.end(), gGame->PrevActors.begin(), gGame->PrevActors.end(), std::inserter(newActorSet, newActorSet.end()), 
		[](const auto a, const auto b) -> bool { 
		return a < b; 
		}
	);

	std::set<uint64> existActorSet;
	std::set_intersection(nowActors.begin(), nowActors.end(), gGame->PrevActors.begin(), gGame->PrevActors.end(), std::inserter(existActorSet, existActorSet.end()),
		[](const auto a, const auto b) -> bool {
			return a < b;
		}
	);

	std::set<uint64> toDeletedActorSet;
	std::set_difference(gGame->PrevActors.begin(), gGame->PrevActors.end(), nowActors.begin(), nowActors.end(), std::inserter(toDeletedActorSet, toDeletedActorSet.end()),
		[](const auto a, const auto b) -> bool {
			return a < b;
		}
		);


	for (auto id : newActorSet)
	{
		auto actor = std::make_shared<Player>();
		actor->GetActorInfo(&tmpPActors[id]);
		actor->Init();

		gGame->AddActor(actor);
	}

	for (auto id : existActorSet)
	{
		auto actor = gGame->FindActor(id);
		actor->GetActorInfo(&tmpPActors[id]);
	}

	for (auto id : toDeletedActorSet)
	{
		auto actor = gGame->FindActor(id);
		gGame->RemoveActor(actor);
	}

	gGame->OnNetwork = true;
}
