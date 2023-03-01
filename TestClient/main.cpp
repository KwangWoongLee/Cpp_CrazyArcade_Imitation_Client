#include "stdafx.h"

#include "HttpManager.h"
#include "ServerCore/ThreadManager.h"
#include "ServerCore/ClientEngine.h"
#include "ServerCore/Session.h"

#include "ServerSession.h"
#include "PacketHandler.h"
#include "Reciever.h"
#include "ReplicationManager.h"


int main(int argc, char** argv)
{
	//std::cout << "������ �� ��ȣ�� �Է��ϼ��� : ";
	//uint64 roomId;
	//std::cin >> roomId;

	try {
		//auto userInfos = HttpManager::GetLoginUsers();
		//auto sessionSize = userInfos.size();


		//for (auto& userInfo : userInfos)
		//{
		//	auto [host, port, tcpRoomId] = HttpManager::EnterRoom(userInfo, roomId);
		//	HttpManager::remoteHost = host;
		//	HttpManager::remotePort = port;

		cout << "���ο� 100���� ���� �ε����� �Է��ϼ��� : " << endl;
		uint64 idx;

		cin >> idx;

		for (uint64 i = idx; i < idx+100; ++i)
		{
			gReplicationManager->Dummys.Push(
				DummyUserInfo{
					1,
					i,
					"testName",
					"testSession",
					"kor"
				}
			);
		}

		PacketHandler::Init();
		ClientEngineRef client = std::make_shared<ClientEngine>(HttpManager::remoteHost, HttpManager::remotePort, std::make_shared<IOCP>(), 100, []() { return std::make_shared<ServerSession>(); });

		ASSERT_CRASH(client->Init());


		gReplicationManager->DoTimer(1000, &ReplicationManager::Update);

		int threadCount = 5;
		for (int i = 0; i < threadCount; ++i)
		{
			gThreadManager->AddThread([=]()
				{
					while (true)
					{
						TLS_LastTickCount = ::GetTickCount64() + 64;

						client->Run(10);

						// ����� �ϰ� ó��
						ThreadManager::DistributeReservedJobs();

						// �۷ι� ť
						ThreadManager::DoGlobalQueueWork();

					}
				});

		}

		gThreadManager->Join();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}


	return 0;
}