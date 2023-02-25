#pragma once
#include "ServerSession.h"

struct DummyUserInfo
{
	uint64 tcpRoomId;
	uint64 aidx;
	string nickname;
	string session;
	string region;
};

class ReplicationManager : public JobQueue
{
public:
	ReplicationManager();
	~ReplicationManager();

	void Update();
	void Add(ServerSessionRef session);
	void Remove(ServerSessionRef session);

	LockQueue<DummyUserInfo> Dummys;

private:
	std::set<ServerSessionRef> mSessions;
};

extern std::shared_ptr<ReplicationManager> gReplicationManager;