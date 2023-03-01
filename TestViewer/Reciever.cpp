#include "stdafx.h"
#include "Reciever.h"
#include "ServerSession.h"
#include "PacketHandler.h"
#include "PacketFactory.h"




shared_ptr<Reciever> gReciever = make_shared<Reciever>();


void Reciever::Push(PacketRef packet)
{
	mPacketQueue.Push(packet);
}

void Reciever::Execute()
{
	auto packet = mPacketQueue.Pop();
	if (packet == nullptr) return;

	HandleFuncs[packet->header.id](mServerSession, packet);

	mPacketQueue.Clear();
}
