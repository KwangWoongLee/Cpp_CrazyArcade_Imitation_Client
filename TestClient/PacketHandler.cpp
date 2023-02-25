#include "stdafx.h"
#include "PacketHandler.h"
#include "PacketFactory.h"
#include "BG.h"
#include "ServerSession.h"

std::vector<function<void(ServerSessionRef,PacketRef)>> HandleFuncs(UINT16_MAX);


void PacketHandler::Init()
{
	HandleFuncs[0] = &PacketHandler::S_PING;
	HandleFuncs[1] = &PacketHandler::S_ENTER_GAME;
	HandleFuncs[2] = &PacketHandler::S_SPAWN;
	HandleFuncs[3] = &PacketHandler::S_DESPAWN;
	HandleFuncs[4] = &PacketHandler::S_ACTION;
	
}


void PacketHandler::S_PING(ServerSessionRef session, PacketRef packet)
{
	Protocol::C_PONG pongPkt;
	session->Send(0, pongPkt);
}

void PacketHandler::S_ENTER_GAME(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_ENTER_GAME>(packet->packet);
}

void PacketHandler::S_SPAWN(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_SPAWN>(packet->packet);
}

void PacketHandler::S_DESPAWN(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_DESPAWN>(packet->packet);
}

void PacketHandler::S_ACTION(ServerSessionRef session, PacketRef packet)
{
	auto pkt = static_pointer_cast<Protocol::S_ACTION>(packet->packet);
}