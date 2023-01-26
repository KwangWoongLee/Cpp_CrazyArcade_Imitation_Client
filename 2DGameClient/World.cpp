#include "stdafx.h"
#include "World.h"

shared_ptr<World> GWorld = make_shared<World>();


void World::AddActor(ActorRef actorRef)
{
	mActors.push_back(actorRef);
	mActorMap[actorRef->GetServerId()] = actorRef;
}

void World::RemoveActor(ActorRef actorRef)
{
	auto myServerId = actorRef->GetServerId();
	auto maxActorIndex = static_cast<uint64>(mActors.size() - 1);

	if (myServerId != maxActorIndex)
	{
		mActors[actorRef->GetServerId()] = mActors[maxActorIndex];

	}

	mActorMap[actorRef->GetServerId()] = nullptr;
	mActors[maxActorIndex] = nullptr;

	mActors.pop_back();
}

void World::Update(float deltaTime)
{

	//델타 시간의 값으로 이번 프레임 게임세계 업데이트
	//mIsUpdatingActors = true;
	//for (auto actor : mActors)
	//{
	//	actor->Update(deltaTime);
	//}
	//mIsUpdatingActors = false;

	////이번 프레임에 업데이트 되지 않은 Actor들을 mActors에 추가
	//for (auto pending : mPendingActors)
	//{
	//	mActors.emplace_back(pending);
	//}
	//mPendingActors.clear();


	//Vector<ActorRef> deadActors;
	//for (auto actor : mActors)
	//{
	//	if (actor->GetState() == Actor::State::EDead)
	//	{
	//		deadActors.emplace_back(actor);
	//	}
	//}


	//for (auto actor : deadActors)
	//{
	//	actor = nullptr;
	//}


}

bool World::EnterWorld(Protocol::S_ENTER_GAME& pkt)
{
	//auto actorSize = pkt.actors_size();
	//if (actorSize > 0)
	//{
	//	auto actors = pkt.actors();
	//	for (auto actor : actors)
	//	{
	//		auto id = static_cast<uint64>(actor.id());
	//		auto name = actor.name();
	//		auto type = actor.type();
	//		auto pos = actor.position();

	//		ActorRef actorRef = nullptr;

	//		switch (type)
	//		{
	//		case Protocol::ACTOR_TYPE_NONE:
	//			break;
	//		case Protocol::ACTOR_TYPE_PLAYER:
	//		{
	//			if (!actor.has_playertype())
	//				break;

	//			auto playerType = actor.playertype();
	//			actorRef = MakeShared<Player>(id, name, playerType, Vector2(pos.x(), pos.y()));
	//			actorRef->Init();
	//		}
	//			break;
	//		case Protocol::ACTOR_TYPE_TILE:
	//			break;
	//		case Protocol::ActorType_INT_MIN_SENTINEL_DO_NOT_USE_:
	//			break;
	//		case Protocol::ActorType_INT_MAX_SENTINEL_DO_NOT_USE_:
	//			break;
	//		default:
	//			break;
	//		}


	//		AddActor(actorRef);
	//	}
	//}

	return true;
}