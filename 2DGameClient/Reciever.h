#pragma once

class Reciever
{
public:
	void RecvJob();
	void Push(BYTE* buf, int32 len);

	void SetSession(ServerSessionRef session) { mServerSession = session; };

private:
	USE_LOCK;

	ServerSessionRef	mServerSession = nullptr; // Cycle
	Queue < pair<BYTE*, int32>  > mRecvQueue;
};


extern shared_ptr<Reciever> GReciever;