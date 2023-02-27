#pragma once
class SendTimer : public JobQueue
{
public:
	SendTimer();
	~SendTimer();

	void Update();


	void Push(std::pair<uint16, std::shared_ptr<google::protobuf::MessageLite>> packet);

	queue<std::pair<uint16, std::shared_ptr<google::protobuf::MessageLite>>> mSendQueue;

	weak_ptr<ServerSession> session; 
};

extern std::shared_ptr<SendTimer> gSendTimer;