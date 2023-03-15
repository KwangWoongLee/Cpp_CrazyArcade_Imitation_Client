#include "stdafx.h"
#include <filesystem>

#include "HttpManager.h"
#include "ServerCore/ThreadManager.h"
#include "ServerCore/ClientEngine.h"
#include "ServerCore/Session.h"

#include "ServerSession.h"
#include "PacketHandler.h"
#include "Reciever.h"
#include "ConfigManager.h"

using std::filesystem::current_path;

int main(int argc, char** argv)
{
	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, SW_SHOW);


	gConfigManager->Init(current_path().string(), "Config\\config.json");

	std::string tcpHost = gConfigManager->Configs["server"]["host"].asString();
	uint16		tcpPort = gConfigManager->Configs["server"]["port"].asInt();
	uint32		maxSession = gConfigManager->Configs["server"]["maxSession"].asInt();
	uint32		zoneCount = gConfigManager->Configs["server"]["zoneCount"].asInt();
	uint32		recvBuffSize = gConfigManager->Configs["server"]["recvBuffSize"].asInt();
	uint32		sendBuffSize = gConfigManager->Configs["server"]["sendBuffSize"].asInt();

	uint64 roomId;

	try {

		cout << "아이디를 입력하세요 : ";
		string id;
		std::cin >> id;

		cout << "비밀번호를 입력하세요 : ";
		string password;
		std::cin >> password;

		HttpManager::Login(id, password);
		cout << "로그인 되었습니다." << endl;

		bool entered = false;
		while (entered == false)
		{
			cout << "다음에 할 행동을 선택하세요." << endl;
			cout << "----------------" << endl;
			cout << "1. 방 목록보기" << endl;
			cout << "2. 방 입장하기" << endl;
			cout << "----------------" << endl;


			int action;
			cin >> action;
			cout << "----------------" << endl;
			switch (action)
			{
			case 1:
				HttpManager::GetRoomList();
				break;
			case 2:
			{
				cout << "입장할 방 ID를 입력하세요" << endl;

				std::cin >> roomId;
				HttpManager::EnterRoom(roomId);

				entered = true;
			}
			break;

			default:
				break;
			}
			cout << "--------------------------------------" << endl;
			cout << endl;
			cout << endl;
			
		}
		
	}
	catch (std::exception& e)
	{
		std::cerr << "웹 서버에서 에러를 던졌습니다. " << e.what() << std::endl;
		std::cerr << "종료합니다." << std::endl;

		exit(1);
	}

	try {
		ASSERT_CRASH(gGame->Init());

		PacketHandler::Init();
		ClientEngineRef client = std::make_shared<ClientEngine>(tcpHost, tcpPort, std::make_shared<IOCP>(), maxSession, []() { return std::make_shared<ServerSession>(); }, 
			recvBuffSize, sendBuffSize);

		ASSERT_CRASH(client->Init());

		gThreadManager->AddThread([=]()
			{
				while (gGame->SHUTDOWN == false)
				{
					client->Run();

				}
			});

		while (gGame->SHUTDOWN == false)
		{
			gGame->RunLoop();
		}

		gGame->Shutdown();


		cout << endl;
		cout << endl;
		cout << "-------------------게임 종료-------------------" << endl;

		cout << "게임 결과를 요청합니다. . ." << endl;
		HttpManager::GetGameResult(roomId);

		gThreadManager->Join();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}


	try {



	}
	catch (std::exception& e)
	{
		std::cerr << "웹 서버에서 에러를 던졌습니다. " << e.what() << std::endl;
		std::cerr << "종료합니다." << std::endl;

		exit(1);
	}
	

	return 0;
}