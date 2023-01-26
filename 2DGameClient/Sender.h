#pragma once
class Sender
{
public:
	void SendJob();
	void Push(SendBufferRef sendBuffer);
	void SetSession(ServerSessionRef session) { mServerSession = session; };

private:
	USE_LOCK;

	ServerSessionRef	mServerSession = nullptr; // Cycle
	Queue<SendBufferRef> mSendQueue;
};


extern shared_ptr<Sender> GSender;