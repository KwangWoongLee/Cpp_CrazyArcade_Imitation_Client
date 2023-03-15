#pragma once
#include <curl/curl.h>
#include <json/json.h>

class HttpManager
{
public:
	static size_t callBackFunk(char* ptr, size_t size, size_t nmemb, string* stream)
	{
		int realsize = size * nmemb;
		stream->append(ptr, realsize);
		return realsize;
	}

	// --------------------------------------------------------------------
	static string UrlPost(const char post_data[])
	{
		CURL* curl;
		CURLcode res;
		curl = curl_easy_init();
		string chunk;

		if (curl)
		{
			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_setopt(curl, CURLOPT_POST, 1);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(post_data));
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callBackFunk);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, (string*)&chunk);
			curl_easy_setopt(curl, CURLOPT_PROXY, "");
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
		}
		if (res != CURLE_OK) {
			throw std::exception("curl error");
		}

		return chunk;
	}
	static void JsonPost(Json::Value& request, Json::Value& response)
	{
		auto encoding = request.toStyledString();
		auto res = UrlPost(encoding.c_str());

		Json::Reader reader;
		bool parsedSuccess = reader.parse(res, response, false);

		if (parsedSuccess == false)
		{
			throw std::exception("Parse failed.");
		}
	}
	static void HandleError(Json::Value& response)
	{
		// 임시 웹서버 에러처리
		int error = response["status"].asInt();
		switch (error)
		{
		case 200:
			break;
		case -103:
			throw std::exception("Unknown Error");
		case -104:
			throw std::exception("Validator Error");
		case -1002:
			throw std::exception("Not Found Acccount");
		case -12:
			throw std::exception("There Isn't Room");

		default:
			throw std::exception("Unhandled Error");
		}
	};

	static void Login(string id, string password);
	static void GetRoomList();
	static void EnterRoom(uint64 roomId);
	static void LeaveRoom();
	static void GetGameResult(uint64 roomId);

	//Version2 Only
	static Json::Value GetLoginUsers();
	static std::tuple<string, uint16, uint64> EnterRoom(Json::Value& userInfo, uint64 roomId);


	static uint64 aidx;
	static string session;
	static string name;
	static string nickname;
	static string region;
	static string id;
	static uint64 nowRoomId;


	static string remoteHost;
	static uint16 remotePort;
	static uint64 remoteRoomId;

private:
	static CURL* curl;
	static const char* url;
	struct curl_slist* list = NULL;
};

