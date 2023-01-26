#include "stdafx.h"
#include "Sender.h"
#include "ServerSession.h"

shared_ptr<Sender> GSender = make_shared<Sender>();

void Sender::SendJob()
{
	WRITE_LOCK;

	while (mSendQueue.empty() == false)
	{
		SendBufferRef sendBuffer = mSendQueue.front();
		mSendQueue.pop();

		mServerSession->Send(sendBuffer);
	}
}

void Sender::Push(SendBufferRef sendBuffer)
{ 
	WRITE_LOCK;

	mSendQueue.push(sendBuffer);
}
