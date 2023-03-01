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

};

extern shared_ptr<Game> gGame;