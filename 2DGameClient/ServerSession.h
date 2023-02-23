#pragma once
#include "Proto/protocol.pb.h"

class ServerSession : public PacketSession
{
public:
	~ServerSession()
	{
		cout << "~ServerSession" << endl;
	}

	virtual void OnConnected() override;
	virtual void OnRecvPacket(PacketHeader header, google::protobuf::io::CodedInputStream& payloadInputStream) override;
	virtual void OnSend(uint32 transferred) override;
	virtual void OnDisconnected() override;

	PlayerRef	mPlayer = nullptr;
	uint64		mPlayerId = 0;
};