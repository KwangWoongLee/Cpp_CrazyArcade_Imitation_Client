#pragma once
#include "Protocol.pb.h"
#include "ServerPacketHandler.h"
#include "Sender.h"

class ServerSession : public PacketSession
{
public:
	~ServerSession()
	{
		cout << "~ServerSession" << endl;
	}

	virtual void OnConnected() override;
	virtual void OnRecvPacket(BYTE* buffer, int32 len) override;
	virtual void OnSend(int32 len) override;
	virtual void OnDisconnected() override;

	uint64 mPlayerId = 0;
	PlayerRef mPlayer = nullptr;
};