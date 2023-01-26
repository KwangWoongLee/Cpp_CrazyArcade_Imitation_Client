#include "stdafx.h"

#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "BufferReader.h"
#include "ServerPacketHandler.h"
#include "ServerSession.h"

int main(int argc, char** argv)
{

	ServerPacketHandler::Init();

	ClientServiceRef service = MakeShared<ClientService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<ServerSession>, // TODO : SessionManager µî
		1);

	ASSERT_CRASH(service->Start());

	GThreadManager->Launch([&]()
		{
			while (true)
			{
				service->GetIocpCore()->Dispatch();
			}
		});

	GThreadManager->Launch([&]()
		{
			ASSERT_CRASH(GGame->Init());

			while (true)
			{
				GGame->RunLoop();
			}
		});

	GThreadManager->Join();
	return 0;
}