#include "stdafx.h"

#include "HttpManager.h"
#include "ServerCore/ThreadManager.h"
#include "ServerCore/ClientEngine.h"
#include "ServerCore/Session.h"

#include "ServerSession.h"
#include "PacketHandler.h"
#include "Reciever.h"
#include "SendTimer.h"




int main(int argc, char** argv)
{
	//try {
	//	cout << "���̵� �Է��ϼ��� : ";
	//	string id;
	//	std::cin >> id;

	//	cout << "��й�ȣ�� �Է��ϼ��� : ";
	//	string password;
	//	std::cin >> password;

	//	HttpManager::Login(id, password);
	//	HttpManager::GetRoomList();

	//	uint64 roomId;
	//	std::cin >> roomId;
	//	HttpManager::EnterRoom(roomId);

	//}
	//catch (std::exception& e)
	//{
	//	std::cerr << "TCP ���� ���� ������ ���� ! " << e.what() << std::endl;
	//	std::cerr << "�����մϴ�." << std::endl;

	//	exit(1);
	//}

	cout << "Test ������ aidx �Է��ϱ�";
	cin >> HttpManager::aidx;

	try {
		ASSERT_CRASH(gGame->Init());

		PacketHandler::Init();
		ClientEngineRef client = std::make_shared<ClientEngine>(HttpManager::remoteHost, HttpManager::remotePort, std::make_shared<IOCP>(), 1, []() { return std::make_shared<ServerSession>(); });

		ASSERT_CRASH(client->Init());

		gThreadManager->AddThread([=]()
			{
				while (true)
				{
					client->Run();

				}
			});

		while (true)
		{
			gGame->RunLoop();

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