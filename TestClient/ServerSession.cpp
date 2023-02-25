#include "stdafx.h"
#include "ServerSession.h"
#include "Reciever.h"
#include "InputManager.h"
#include "PacketHandler.h"
#include "PacketFactory.h"
#include "HttpManager.h"
#include "ReplicationManager.h"

void ServerSession::OnConnected()
{
	auto serverSessionRef = static_pointer_cast<ServerSession>(shared_from_this());

	gReplicationManager->DoAsync(&ReplicationManager::Add, serverSessionRef);
}


void ServerSession::OnRecvPacket(PacketHeader header, google::protobuf::io::CodedInputStream& payloadInputStream)
{
	if (header.id >= 10 || header.id < 0)
	{
		DisConnect("Packet Range Over");
		return;
	}

	auto packet = PacketFactory::GetInstance().MakePacket(header, payloadInputStream);
	if(packet == nullptr)
	{
		DisConnect("Incorrect Packet Transfered");
		return;
	}

	auto serverSessionRef = static_pointer_cast<ServerSession>(shared_from_this());
	
	HandleFuncs[header.id](serverSessionRef, packet);
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
