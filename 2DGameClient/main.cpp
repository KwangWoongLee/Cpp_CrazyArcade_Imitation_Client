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
	//	cout << "아이디를 입력하세요 : ";
	//	string id;
	//	std::cin >> id;

	//	cout << "비밀번호를 입력하세요 : ";
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
	//	std::cerr << "TCP 서버 정보 얻어오기 실패 ! " << e.what() << std::endl;
	//	std::cerr << "종료합니다." << std::endl;

	//	exit(1);
	//}

	cout << "Test 용으로 aidx 입력하기";
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