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
		if(session.lock()->Send(packetId, *packet) == true)
			mSendQueue.pop();
	}

	AsyncSendJob();
}

void SendTimer::AsyncSendJob()
{
	// TLS 작업이라 No Lock
	while (TLS_SendSessionQueue.empty() == false)
	{
		auto sessionRef = TLS_SendSessionQueue.front();

		if (sessionRef->AsyncSend() == true) // 남은 Send 작업이 없을 경우, 제거
		{
			sessionRef = nullptr;
			TLS_SendSessionQueue.pop();
		}
	}
}

void SendTimer::Push(std::pair<uint16, std::shared_ptr<google::protobuf::MessageLite>> packet)
{
	mSendQueue.push(packet);
}
