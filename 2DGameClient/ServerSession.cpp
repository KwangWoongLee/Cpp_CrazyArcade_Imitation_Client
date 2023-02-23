#include "stdafx.h"
#include "ServerSession.h"
#include "Reciever.h"
#include "InputManager.h"
#include "PacketHandler.h"
#include "PacketFactory.h"
#include "HttpManager.h"
#include "SendTimer.h"

void ServerSession::OnConnected()
{
	auto serverSessionRef = static_pointer_cast<ServerSession>(shared_from_this());
	gReciever->SetSession(serverSessionRef);
	gInputManager->SetSession(serverSessionRef);
	gSendTimer->session = serverSessionRef;

	Protocol::C_ENTER_GAME enterGamePkt;
	enterGamePkt.set_aidx(HttpManager::aidx);
	enterGamePkt.set_roomid(HttpManager::remoteRoomId);
	enterGamePkt.set_nickname(HttpManager::nickname);
	enterGamePkt.set_playertype(Protocol::PLAYER_TYPE_BAZZI);

	std::shared_ptr<google::protobuf::MessageLite> sharedPacket = std::make_shared<Protocol::C_ENTER_GAME>(enterGamePkt);
	gSendTimer->DoAsync(&SendTimer::Push, std::pair{ static_cast<uint16>(1), sharedPacket });
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
