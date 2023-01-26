#include "stdafx.h"
#include "ServerSession.h"
#include "Reciever.h"

void ServerSession::OnConnected()
{
	auto serverSessionRef = static_pointer_cast<ServerSession>(shared_from_this());
	GSender->SetSession(serverSessionRef);
	GReciever->SetSession(serverSessionRef);

	Protocol::C_ENTER_GAME enterGamePkt;
	enterGamePkt.set_playertype(Protocol::PLAYER_TYPE_BAZZI);

	//레디스에서 룸키를 가져올 예정
	enterGamePkt.set_roomkey("1");
	auto sendBuffer = ServerPacketHandler::MakeSendBuffer(enterGamePkt);

	GSender->Push(sendBuffer);
}

void ServerSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	PacketSessionRef session = GetPacketSessionRef();
	
	//임시
	BYTE* buf = new BYTE[len];
	copy(buffer, buffer + len, buf);
	
	GReciever->Push(buf, len);
	//PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

	// TODO : packetId 대역 체크
	//ServerPacketHandler::HandlePacket(session, buffer, len);
	
}

void ServerSession::OnSend(int32 len)
{
	//cout << "OnSend Len = " << len << endl;
}

void ServerSession::OnDisconnected()
{
	//리커넥트 or 종료
	mPlayer = nullptr;
	GGame->Shutdown();
}
