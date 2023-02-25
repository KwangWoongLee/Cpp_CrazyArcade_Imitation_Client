#pragma once

class Reciever
{
public:
	void SetSession(ServerSessionRef session) { mServerSession = session; };

	void Push(PacketRef packet);
	void Execute();
private:
	ServerSessionRef	mServerSession = nullptr; // Cycle
	LockQueue<PacketRef> mPacketQueue;
};


extern shared_ptr<Reciever> gReciever;