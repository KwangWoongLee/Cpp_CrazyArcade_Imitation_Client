#include "stdafx.h"
#include "HttpManager.h"

const char* HttpManager::url = "http://localhost:8080";
string HttpManager::id;
uint64 HttpManager::aidx = 10;
string HttpManager::session;
string HttpManager::name;
string HttpManager::nickname = "test";
string HttpManager::region = "kor";
uint64 HttpManager::nowRoomId = 1;


string HttpManager::remoteHost = "61.77.43.136";
uint16 HttpManager::remotePort = 9999;
uint64 HttpManager::remoteRoomId = 1;


void HttpManager::Login(string id, string password)
{
	Json::Value request, response;
	request["cmd"] = 103;
	request["aidx"] = 0;
	request["session"] = "";
	request["login_type"] = 1;
	request["server_version"] = "1.0.0";
	request["login_id"] = id;
	request["password"] = password;

	JsonPost(request, response);

	HandleError(response);

	auto data = response["data"];
	aidx = data["user_info"]["aidx"].asUInt64();
	session = data["user_info"]["session"].asString();
	name = data["user_info"]["name"].asString();
	nickname = data["user_info"]["nickname"].asString();
	region = data["user_info"]["region"].asString();
}

void HttpManager::GetRoomList()
{
	Json::Value request, response;
	request["cmd"] = 5009;
	request["aidx"] = aidx;
	request["session"] = session;
	request["region"] = region;
	
	
	JsonPost(request, response);

	HandleError(response);

	auto data = response["data"];
	auto roomInfos = data["roomInfos"];
	auto roomSize = roomInfos.size();
	for (auto roomInfo : roomInfos)
	{
		uint64 roomHost = roomInfo["hostAidx"]["low"].asUInt64();
		string title = roomInfo["title"].asString();
		uint32 mapId = roomInfo["mapId"].asUInt();
		uint32 minMemberCount = roomInfo["minMemberCount"].asUInt();
		uint32 maxMemberCount = roomInfo["maxMemberCount"].asUInt();
		uint64 roomId = roomInfo["roomId"]["low"].asUInt64();

		cout << "RoomID (" << roomId << ")'s Title : " << title << endl;
	}
}

void HttpManager::EnterRoom(uint64 roomId)
{
	Json::Value request, response;
	request["cmd"] = 5005;
	request["aidx"] = aidx;
	request["session"] = session;
	request["region"] = region;
	request["name"] = name;
	request["room_id"] = roomId;

	JsonPost(request, response);

	HandleError(response);

	auto data = response["data"];
	auto remoteServer = data["remoteInfo"];
	string host = remoteServer["host"].asString();
	uint16 port = remoteServer["port"].asUInt();
	uint64 tcpRoomId = remoteServer["tcpRoomId"]["low"].asUInt64();

	cout << "접속정보 : " << host << ":" << port << "의 방 \"" << tcpRoomId << "\" 으로 접속합니다." << endl;

	remoteHost = host;
	remotePort = port;
	remoteRoomId = tcpRoomId;
}

std::tuple<string, uint16, uint64> HttpManager::EnterRoom(Json::Value& userInfo, uint64 roomId)
{
	Json::Value request, response;
	request["cmd"] = 5005;
	request["aidx"] = userInfo["aidx"].asUInt64();
	request["session"] = userInfo["session"].asString();
	request["region"] = userInfo["region"].asString();
	request["name"] = userInfo["name"].asString();
	request["room_id"] = roomId;

	JsonPost(request, response);

	HandleError(response);

	auto data = response["data"];
	auto remoteServer = data["remoteInfo"];
	string host = remoteServer["host"].asString();
	uint16 port = remoteServer["port"].asUInt();
	uint64 tcpRoomId = remoteServer["tcpRoomId"]["low"].asUInt64();

	return std::tuple(host, port, tcpRoomId);
}

void HttpManager::LeaveRoom()
{
	Json::Value request, response;
	request["cmd"] = 5007;
	request["aidx"] = aidx;
	request["session"] = session;
	request["roomId"] = nowRoomId;

	JsonPost(request, response);

	HandleError(response);

	auto data = response["data"];
}

Json::Value HttpManager::GetLoginUsers()
{
	Json::Value request, response;
	request["cmd"] = 5011;

	JsonPost(request, response);

	HandleError(response);

	auto data = response["data"];
	auto userInfos = data["user_infos"];

	return userInfos;

}
