#pragma once
#include "Proto/protocol.pb.h"

class Game
{
public:
	Game();

	//게임 기본 3루프
	//게임 초기화
	bool Init();
	void GenerateOutput(const google::protobuf::RepeatedPtrField<Protocol::Pos>& poss);
	uint32		mTicksCount;

	std::atomic<bool> OnNetwork = false;

	uint32		zoneCount;
	uint32		viewSize;
	uint64		mLastSendTick;
	uint64		delayTick;
private:
	//SDL 윈도우
	SDL_Window*	mWindow;
	//SDL 렌더러
	SDL_Renderer* mRenderer;
	//TTF FONT
	TTF_Font* font;
	// ViewTexture
	SDL_Texture* mViewTexture;

};

extern shared_ptr<Game> gGame;