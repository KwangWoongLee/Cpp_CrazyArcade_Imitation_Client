#pragma once
#include "Proto/protocol.pb.h"

class Game
{
public:
	Game();

	//���� �⺻ 3����
	//���� �ʱ�ȭ
	bool Init();
	void GenerateOutput(const google::protobuf::RepeatedPtrField<Protocol::Pos>& poss);
	uint32		mTicksCount;

	std::atomic<bool> OnNetwork = false;

	uint32		zoneCount;
	uint32		viewSize;
	uint64		mLastSendTick;
	uint64		delayTick;
private:
	//SDL ������
	SDL_Window*	mWindow;
	//SDL ������
	SDL_Renderer* mRenderer;
	//TTF FONT
	TTF_Font* font;
	// ViewTexture
	SDL_Texture* mViewTexture;

};

extern shared_ptr<Game> gGame;