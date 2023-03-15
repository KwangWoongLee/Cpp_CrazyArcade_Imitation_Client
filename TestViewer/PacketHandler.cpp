#include "stdafx.h"
#include "PacketHandler.h"
#include "ServerSession.h"

std::vector<function<void(PacketSessionRef, PacketHeader, google::protobuf::io::CodedInputStream&)>> HandleFuncs(UINT16_MAX);


void PacketHandler::Init()
{
	HandleFuncs[0] = &PacketHandler::S_PING;
	HandleFuncs[1] = &PacketHandler::S_TEST;
}

void PacketHandler::S_PING(PacketSessionRef session , PacketHeader header, google::protobuf::io::CodedInputStream& inputStream)
{
	Protocol::S_PING pkt;

	if (false == pkt.ParseFromCodedStream(&inputStream))
	{
		session->DisConnect("Packet Parse Failed");
		return;
	}

	auto now  = GetTickCount64();
	if (gGame->mLastSendTick == 0)
		return;
	else
	{
		auto diff = now - gGame->mLastSendTick;

		gGame->delayTick = diff;
	}
}

void PacketHandler::S_TEST(PacketSessionRef session, PacketHeader header, google::protobuf::io::CodedInputStream& inputStream)
{
	Protocol::S_TEST pkt;

	if (false == pkt.ParseFromCodedStream(&inputStream))
	{
		session->DisConnect("Packet Parse Failed");
		return;
	}

	Protocol::C_ACTION actionPkt;
	session->Send(2, actionPkt);
	gGame->mLastSendTick = GetTickCount64();

	gGame->GenerateOutput(pkt.poss());



}
