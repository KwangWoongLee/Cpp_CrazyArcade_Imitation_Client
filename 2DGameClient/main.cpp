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

		cout << "���̵� �Է��ϼ��� : ";
		string id;
		std::cin >> id;

		cout << "��й�ȣ�� �Է��ϼ��� : ";
		string password;
		std::cin >> password;

		HttpManager::Login(id, password);
		cout << "�α��� �Ǿ����ϴ�." << endl;

		bool entered = false;
		while (entered == false)
		{
			cout << "������ �� �ൿ�� �����ϼ���." << endl;
			cout << "----------------" << endl;
			cout << "1. �� ��Ϻ���" << endl;
			cout << "2. �� �����ϱ�" << endl;
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
				cout << "������ �� ID�� �Է��ϼ���" << endl;

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
		std::cerr << "�� �������� ������ �������ϴ�. " << e.what() << std::endl;
		std::cerr << "�����մϴ�." << std::endl;

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
		cout << "-------------------���� ����-------------------" << endl;

		cout << "���� ����� ��û�մϴ�. . ." << endl;
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
		std::cerr << "�� �������� ������ �������ϴ�. " << e.what() << std::endl;
		std::cerr << "�����մϴ�." << std::endl;

		exit(1);
	}
	

	return 0;
}