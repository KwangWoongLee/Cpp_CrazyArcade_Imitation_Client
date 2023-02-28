#pragma once

class Game
{
public:
	Game();

	//���� �⺻ 3����
	//���� �ʱ�ȭ
	bool Init();
	//���� ���� ����
	void RunLoop();
	//���� ����
	void Shutdown();

	//���� ������ (��)�ε�
	bool LoadData(std::string_view mapFileName = "Assets/Map.csv", std::string_view collisionFileName = "Assets/MapCollision.csv");
	void UnloadData();
	
	//Actor�߰� �� �����Լ�
	void AddActor(ActorRef actor);
	void RemoveActor(ActorRef actor);
	std::vector<ActorRef>& GetActors() { return mActors; }

	//SpriteComponent �߰�, ����
	void AddSprite(SpriteComponentRef sprite);
	void RemoveSprite(SpriteComponentRef sprite);

	std::map<uint64, ActorRef> mIdToActor;
	std::set<uint64> PrevActors;

	ActorRef FindActor(uint64 id);
	uint32		mTicksCount;

	std::atomic<bool> OnNetwork = false;

private:
	//���� ���� ���� �Լ�
	void ProcessInput();
	void ProcessRecv();
	void UpdateGame(float deltaTime);
	void GenerateOutput();

	//������Ʈ �Ϸ�� Actor vector
	std::vector<ActorRef> mActors;
	//������Ʈ �Ϸ���� ���� Actor vector;
	std::vector<ActorRef> mPendingActors;


	// SpriteComponent Vector // Game�� �׸��� ���� Sprite Vector
	std::vector<SpriteComponentRef> mSprites;

	int GetGameScale() const { return mGameScale; }

	int mTileSizeX;
	int mTileSizeY;
	std::vector<short> mMapRange; // 0 : minX , 1 : maxX, 2 : minY, 3 : maxY

	int mGameScale = 1;

	//SDL ������
	SDL_Window*	mWindow;
	//SDL ������
	SDL_Renderer* mRenderer;

	//���� ���� �Ǵ�
	bool		mIsRunning;
	//���� ƽ���� ������ ����
	uint32		mSendJobTick{};
	//Actor ������Ʈ �Ϸ� Ȯ�� �Ǵ�
	bool		mIsUpdatingActors;
	
	std::vector<PlayerRef> mPlayers;
	//Vector<BombRef> mBombs;
	//Vector<BoomRef> mBooms;

};

extern shared_ptr<Game> gGame;