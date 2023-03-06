#include "stdafx.h"
#include "PacketHandler.h"
#include "ServerSession.h"

std::vector<function<void(PacketSessionRef, PacketHeader, google::protobuf::io::CodedInputStream&)>> HandleFuncs(UINT16_MAX);


void PacketHandler::Init()
{
	HandleFuncs[1] = &PacketHandler::S_TEST;
}

void PacketHandler::S_TEST(PacketSessionRef session, PacketHeader header, google::protobuf::io::CodedInputStream& inputStream)
{
	Protocol::S_TEST pkt;

	if (false == pkt.ParseFromCodedStream(&inputStream))
	{
		session->DisConnect("Packet Parse Failed");
		return;
	}

	gGame->GenerateOutput(pkt.actors());

}
