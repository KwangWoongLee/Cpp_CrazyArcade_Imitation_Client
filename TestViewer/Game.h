#pragma once
#include "Proto/protocol.pb.h"

class Game
{
public:
	Game();

	//게임 기본 3루프
	//게임 초기화
	bool Init();
	void GenerateOutput(const google::protobuf::RepeatedPtrField<Protocol::PActor>& actors);
	uint32		mTicksCount;

	std::atomic<bool> OnNetwork = false;

private:
	//SDL 윈도우
	SDL_Window*	mWindow;
	//SDL 렌더러
	SDL_Renderer* mRenderer;

};

extern shared_ptr<Game> gGame;