#pragma once

class ServerSession;

using ServerSessionRef = shared_ptr<ServerSession>;

class ServerSessionManager
{
public:
	void Add(ServerSessionRef session);
	void Remove(ServerSessionRef session);

private:
	USE_LOCK;
	std::set<ServerSessionRef> mSessions;
};

extern ServerSessionManager gSessionManager;
