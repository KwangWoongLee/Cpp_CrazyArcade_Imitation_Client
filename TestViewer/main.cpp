#include "stdafx.h"

#include "ServerCore/ThreadManager.h"
#include "ServerCore/ClientEngine.h"
#include "ServerCore/Session.h"

#include "ServerSession.h"
#include "PacketHandler.h"




int main(int argc, char** argv)
{
	string host = "61.77.43.136";
	uint32 port = 7777;

	try {
		ASSERT_CRASH(gGame->Init());

		PacketHandler::Init();
		ClientEngineRef client = std::make_shared<ClientEngine>(host, port, std::make_shared<IOCP>(), 1, []() { return std::make_shared<ServerSession>(); });

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