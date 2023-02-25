#include "stdafx.h"
#include "ServerSessionManager.h"
#include "ServerSession.h"
#include "Proto/protocol.pb.h"

ServerSessionManager gSessionManager;

void ServerSessionManager::Add(ServerSessionRef session)
{
	WRITE_LOCK;
	mSessions.insert(session);
}

void ServerSessionManager::Remove(ServerSessionRef session)
{
	WRITE_LOCK;
	mSessions.erase(session);
}
