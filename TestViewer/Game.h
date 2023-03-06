#pragma once
#include "Proto/protocol.pb.h"

class Game
{
public:
	Game();

	//���� �⺻ 3����
	//���� �ʱ�ȭ
	bool Init();
	void GenerateOutput(const google::protobuf::RepeatedPtrField<Protocol::PActor>& actors);
	uint32		mTicksCount;

	std::atomic<bool> OnNetwork = false;

private:
	//SDL ������
	SDL_Window*	mWindow;
	//SDL ������
	SDL_Renderer* mRenderer;

};

extern shared_ptr<Game> gGame;