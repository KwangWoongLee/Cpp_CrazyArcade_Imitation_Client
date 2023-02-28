#include "stdafx.h"
#include "ServerSession.h"
#include "PacketHandler.h"
#include "PacketFactory.h"
#include "Reciever.h"

void ServerSession::OnConnected()
{
	auto serverSessionRef = static_pointer_cast<ServerSession>(shared_from_this());

	Protocol::C_ENTER_GAME enterGamePkt;
	enterGamePkt.set_aidx(9999);
	enterGamePkt.set_roomid(1);
	enterGamePkt.set_nickname("Test");
	enterGamePkt.set_playertype(Protocol::PLAYER_TYPE_BAZZI);

	Send(1, enterGamePkt);
}


void ServerSession::OnRecvPacket(PacketHeader header, google::protobuf::io::CodedInputStream& payloadInputStream)
{
	if (header.id >= 10 || header.id < 0)
	{
		DisConnect("Packet Range Over");
		return;
	}

	auto packet = PacketFactory::GetInstance().MakePacket(header, payloadInputStream);
	if (packet == nullptr)
	{
		DisConnect("Incorrect Packet Transfered");
		return;
	}

	gReciever->Push(packet);
}


void ServerSession::OnSend(uint32 transferred)
{
}

void ServerSession::OnDisconnected()
{
	//리커넥트 or 종료
	mPlayer = nullptr;
	gGame->Shutdown();
}
