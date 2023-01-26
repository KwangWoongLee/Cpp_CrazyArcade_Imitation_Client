#include "stdafx.h"
#include "Reciever.h"
#include "ServerSession.h"
#include "ServerPacketHandler.h"


shared_ptr<Reciever> GReciever = make_shared<Reciever>();

void Reciever::RecvJob() {
	WRITE_LOCK;
	while (mRecvQueue.empty() == false)
	{
		PacketSessionRef session = mServerSession->GetPacketSessionRef();

		auto front = mRecvQueue.front();
		mRecvQueue.pop();

		ServerPacketHandler::HandlePacket(session, front.first, front.second);

		delete[] front.first;
	}
}


void Reciever::Push(BYTE* buf, int32 len) {
	WRITE_LOCK;
	mRecvQueue.push({ buf,len });
}