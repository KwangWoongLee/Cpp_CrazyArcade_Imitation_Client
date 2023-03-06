#include "stdafx.h"

#include "ServerCore/ThreadManager.h"
#include "ServerCore/ClientEngine.h"
#include "ServerCore/Session.h"

#include "ServerSession.h"
#include "PacketHandler.h"
#include "ConfigManager.h"

#include <filesystem>
using std::filesystem::current_path;



int main(int argc, char** argv)
{
	gConfigManager->Init(current_path().string(), "Config\\config.json");

	std::string tcpHost = gConfigManager->Configs["server"]["host"].asString();
	uint16		tcpPort = gConfigManager->Configs["server"]["port"].asInt();
	uint32		maxSession = gConfigManager->Configs["server"]["maxSession"].asInt();

	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, SW_HIDE);

	try {
		ASSERT_CRASH(gGame->Init());

		PacketHandler::Init();
		ClientEngineRef client = std::make_shared<ClientEngine>(tcpHost, tcpPort, std::make_shared<IOCP>(), maxSession, []() { return std::make_shared<ServerSession>(); });

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