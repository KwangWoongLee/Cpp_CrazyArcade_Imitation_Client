#pragma once

class Game
{
public:
	Game();

	//게임 기본 3루프
	//게임 초기화
	bool Init();
	//게임 루프 시작
	void RunLoop();
	//게임 종료
	void Shutdown();

	//게임 데이터 (언)로드
	bool LoadData(std::string_view mapFileName = "Assets/Map.csv", std::string_view collisionFileName = "Assets/MapCollision.csv");
	void UnloadData();
	
	//Actor추가 및 삭제함수
	void AddActor(ActorRef actor);
	void RemoveActor(ActorRef actor);
	std::vector<ActorRef>& GetActors() { return mActors; }

	//SpriteComponent 추가, 삭제
	void AddSprite(SpriteComponentRef sprite);
	void RemoveSprite(SpriteComponentRef sprite);

	//이미지 파일에서 Texture로 변환
	SDL_Texture* GetTexture(const std::string& fileName);

	//tilemap 가져오기
	//bool ReadTileMap(const std::string& fileName);
	//void AddTile(class TileRef bomb);
	//void RemoveTile(class TileRef bomb, const Vector2& pos);
	//Vector<class TileRef>& GetTiles() { return mTiles; }
	//Vector<Vector<int>>& GetTileMapToInt() { return mTileMapToInt; }
	//Vector<Vector<Tile::TileType>>& GetTileMapToType() { return mTileMapToType; }

	//게임 구체적 내용
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

	std::atomic<bool> OnNetwork = false;

private:
	//게임 루프 헬퍼 함수
	void ProcessInput();
	void ProcessRecv();
	void UpdateGame(float deltaTime);
	void GenerateOutput();

	//업데이트 완료된 Actor vector
	std::vector<ActorRef> mActors;
	//업데이트 완료되지 않은 Actor vector;
	std::vector<ActorRef> mPendingActors;


	// SpriteComponent Vector // Game이 그리기 위한 Sprite Vector
	std::vector<SpriteComponentRef> mSprites;

	// Texture map  <filename, SDL_Texture*> // Texture 재활용을 위한 vector
	std::map<std::string, SDL_Texture*> mTextures;

	//타일맵
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

	//SDL 윈도우
	SDL_Window*	mWindow;
	//SDL 렌더러
	SDL_Renderer* mRenderer;

	//게임 실행 판단
	bool		mIsRunning;
	//현재 틱값을 갱신할 변수
	uint32		mSendJobTick{};
	//Actor 업데이트 완료 확인 판단
	bool		mIsUpdatingActors;
	
	std::vector<PlayerRef> mPlayers;
	//Vector<BombRef> mBombs;
	//Vector<BoomRef> mBooms;

};

extern shared_ptr<Game> gGame;