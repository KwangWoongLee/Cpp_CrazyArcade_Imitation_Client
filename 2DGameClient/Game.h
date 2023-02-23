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

	//�̹��� ���Ͽ��� Texture�� ��ȯ
	SDL_Texture* GetTexture(const std::string& fileName);

	//tilemap ��������
	//bool ReadTileMap(const std::string& fileName);
	//void AddTile(class TileRef bomb);
	//void RemoveTile(class TileRef bomb, const Vector2& pos);
	//Vector<class TileRef>& GetTiles() { return mTiles; }
	//Vector<Vector<int>>& GetTileMapToInt() { return mTileMapToInt; }
	//Vector<Vector<Tile::TileType>>& GetTileMapToType() { return mTileMapToType; }

	//���� ��ü�� ����
	//void AddPlayer(class PlayerRef player);
	//void RemovePlayer(class PlayerRef player);
	//Vector<class PlayerRef>& GetPlayers() { return mPlayers; }

	//void AddBomb(class BombRef bomb);
	//void RemoveBomb(class BombRef bomb);
	//Vector<class BombRef>& GetBombs() { return mBombs; }

	//void AddBoom(class BoomRef boom);
	//void RemoveBoom(class BoomRef boom);
	//Vector<class BoomRef>& GetBooms() { return mBooms; }


	//bool EnterWorld(ServerSessionRef serverSession, Protocol::S_ENTER_GAME& pkt);

	std::map<uint64, ActorRef> mIdToActor;
	ActorRef FindActor(uint64 id);
	uint32		mTicksCount;

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

	// Texture map  <filename, SDL_Texture*> // Texture ��Ȱ���� ���� vector
	std::map<std::string, SDL_Texture*> mTextures;

	//Ÿ�ϸ�
	std::vector<TileRef> mTiles;
	std::vector<std::vector<int>> mTileMapToInt;
	std::vector<std::vector<Tile::TileType>> mTileMapToType;
	int GetTileSizeX() const { return mTileSizeX; }
	int GetTileSizeY() const { return mTileSizeY; }
	void SetTileSizeXY(int x, int y);
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