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
	std::vector<PacketRef> packets;
	mPacketQueue.PopAll(packets);

	for (auto packet : packets)
	{
		HandleFuncs[packet->header.id](mServerSession, packet);
	}
}
