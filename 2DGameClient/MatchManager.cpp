#include "stdafx.h"
#include "MatchManager.h"
#include "MatchClient.h"

std::shared_ptr<MatchManager> gMatchManager = std::make_shared<MatchManager>();

MatchManager::MatchManager()
{
}

MatchManager::~MatchManager()
{
	mMatchClient = nullptr;	
}

bool MatchManager::Init(std::string host, uint16 port)
{
	std::string sPort = to_string(port);
	auto serverAddress = host.append(":").append(sPort);
	
	mMatchClient = std::make_shared<MatchClient>(serverAddress , grpc::CreateChannel(serverAddress, grpc::InsecureChannelCredentials()) );

	if (mMatchClient->CallEnterRoom() == false)
	{
		return false;
	}
	mServerAdded = true;

	return true;
}

