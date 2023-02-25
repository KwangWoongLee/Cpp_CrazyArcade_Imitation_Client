#include "stdafx.h"
#include "ReplicationManager.h"
#include "HttpManager.h"
#include "Proto/protocol.pb.h"
#include <random>

std::shared_ptr<ReplicationManager> gReplicationManager = std::make_shared<ReplicationManager>();

ReplicationManager::ReplicationManager()
{
}

ReplicationManager::~ReplicationManager()
{
}

void ReplicationManager::Update()
{
	DoTimer(250, &ReplicationManager::Update);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 4);

	for (auto session : mSessions)
	{
		Protocol::C_ACTION actionPkt;

		actionPkt.add_playeractions(static_cast<Protocol::Action>(dis(gen)));
		session->Send(2, actionPkt);
	}
}

void ReplicationManager::Add(ServerSessionRef session)
{
	auto dummy = Dummys.Pop();
	if (dummy.aidx == 0) return;

	Protocol::C_ENTER_GAME enterGamePkt;
	enterGamePkt.set_aidx(dummy.aidx);
	enterGamePkt.set_roomid(dummy.tcpRoomId);
	enterGamePkt.set_nickname(dummy.nickname);
	enterGamePkt.set_playertype(Protocol::PLAYER_TYPE_BAZZI);

	session->Send(1, enterGamePkt);

	mSessions.insert(session);
}

void ReplicationManager::Remove(ServerSessionRef session)
{
	mSessions.erase(session);
}
