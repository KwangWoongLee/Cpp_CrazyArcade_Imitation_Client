#include "stdafx.h"
#include "SendTimer.h"
#include "ServerSession.h"

shared_ptr<SendTimer> gSendTimer = make_shared<SendTimer>();

SendTimer::SendTimer()
{
}

SendTimer::~SendTimer()
{
}

void SendTimer::Update()
{
	DoTimer(100, &SendTimer::Update);

	while (!mSendQueue.empty())
	{
		auto [packetId, packet] = mSendQueue.front();
		mSendQueue.pop();
		session.lock()->Send(packetId, *packet);
	}


	return;
}

void SendTimer::Push(std::pair<uint16, std::shared_ptr<google::protobuf::MessageLite>> packet)
{
	mSendQueue.push(packet);
}
