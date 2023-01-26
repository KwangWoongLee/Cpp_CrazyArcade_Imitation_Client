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

	//���𽺿��� ��Ű�� ������ ����
	enterGamePkt.set_roomkey("1");
	auto sendBuffer = ServerPacketHandler::MakeSendBuffer(enterGamePkt);

	GSender->Push(sendBuffer);
}

void ServerSession::OnRecvPacket(BYTE* buffer, int32 len)
{
	PacketSessionRef session = GetPacketSessionRef();
	
	//�ӽ�
	BYTE* buf = new BYTE[len];
	copy(buffer, buffer + len, buf);
	
	GReciever->Push(buf, len);
	//PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

	// TODO : packetId �뿪 üũ
	//ServerPacketHandler::HandlePacket(session, buffer, len);
	
}

void ServerSession::OnSend(int32 len)
{
	//cout << "OnSend Len = " << len << endl;
}

void ServerSession::OnDisconnected()
{
	//��Ŀ��Ʈ or ����
	mPlayer = nullptr;
	GGame->Shutdown();
}
