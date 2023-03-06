#include "stdafx.h"

#include "HttpManager.h"
#include "ServerCore/ThreadManager.h"
#include "ServerCore/ClientEngine.h"
#include "ServerCore/Session.h"

#include "ServerSession.h"
#include "PacketHandler.h"
#include "Reciever.h"
#include "ReplicationManager.h"
#include "ConfigManager.h"

#include <filesystem>
using std::filesystem::current_path;

int main(int argc, char** argv)
{
	gConfigManager->Init(current_path().string(), "Config\\config.json");

	std::string tcpHost = gConfigManager->Configs["test"]["host"].asString();
	uint16		tcpPort = gConfigManager->Configs["test"]["port"].asInt();
	uint32		maxSession = gConfigManager->Configs["test"]["maxSession"].asInt();
	//std::cout << "접속할 방 번호를 입력하세요 : ";
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

		cout << "새로운" << maxSession <<" 명의 시작 인덱스를 입력하세요 : " << endl;
		uint64 idx;

		cin >> idx;

		for (uint64 i = idx; i < idx + maxSession; ++i)
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
		ClientEngineRef client = std::make_shared<ClientEngine>(tcpHost, tcpPort, std::make_shared<IOCP>(), maxSession, []() { return std::make_shared<ServerSession>(); });

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

						// 예약된 일감 처리
						ThreadManager::DistributeReservedJobs();

						// 글로벌 큐
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