#include "stdafx.h"

#include "ServerCore/ThreadManager.h"
#include "ServerCore/ClientEngine.h"
#include "ServerCore/Session.h"

#include "ServerSession.h"
#include "PacketHandler.h"
#include "ConfigManager.h"

#include "Proto/protocol.pb.h"

#include <filesystem>
using std::filesystem::current_path;



int main(int argc, char** argv)
{
	gConfigManager->Init(current_path().string(), "Config\\config.json");

	std::string tcpHost = gConfigManager->Configs["test"]["host"].asString();
	uint16		tcpPort = gConfigManager->Configs["test"]["port"].asInt();
	uint32		maxSession = 1;
	uint32		viewSize = gConfigManager->Configs["test"]["viewSize"].asInt();
	uint32		zoneCount = gConfigManager->Configs["test"]["zoneCount"].asInt();
	uint32		recvBuffSize = gConfigManager->Configs["test"]["recvBuffSize"].asInt();
	uint32		sendBuffSize = gConfigManager->Configs["test"]["sendBuffSize"].asInt();

	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, SW_SHOW);

	try {
		gGame->viewSize = viewSize;
		gGame->zoneCount = zoneCount;
		ASSERT_CRASH(gGame->Init());


		PacketHandler::Init();
		ClientEngineRef client = std::make_shared<ClientEngine>(tcpHost, tcpPort, std::make_shared<IOCP>(), maxSession, []() { return std::make_shared<ServerSession>(); },
			recvBuffSize, sendBuffSize);

		ASSERT_CRASH(client->Init());


		while (true)
		{
			client->Run();
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	

	return 0;
}