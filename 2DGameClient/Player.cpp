#include "stdafx.h"
#include "Game.h"

Player::Player(uint64 serverId, string name, Protocol::PlayerType type, Vector2 pos, bool myPlayer)
	:Actor(serverId, name, pos),
	mPlayerType(type)
	,mDeathTimer(0.f)
	, mMyPlayer(myPlayer)
{
	mType = Protocol::ActorType::ACTOR_TYPE_NONE;

	SetScale(0.5f);
}

Player::~Player()
{
}

void Player::Init()
{
	AnimationComponentRef asc = MakeShared<AnimationComponent>(shared_from_this(), 200);

	SDL_Texture* idle = GGame->GetTexture("Assets/idle.bmp");
	SDL_Texture* down = GGame->GetTexture("Assets/down.bmp");
	SDL_Texture* left = GGame->GetTexture("Assets/left.bmp");
	SDL_Texture* right = GGame->GetTexture("Assets/right.bmp");
	SDL_Texture* up = GGame->GetTexture("Assets/up.bmp");
	SDL_Texture* bubble = GGame->GetTexture("Assets/bazziBubble.bmp");
	SDL_Texture* tempdie = GGame->GetTexture("Assets/bazziDie.bmp");

	asc->AddAnimTextures("idle", idle);
	asc->AddAnimTextures("down", down);
	asc->AddAnimTextures("left", left);
	asc->AddAnimTextures("right", right);
	asc->AddAnimTextures("up", up);
	asc->AddAnimTextures("bubble", bubble);
	asc->AddAnimTextures("tempdie", tempdie);

	asc->SetAnimTexture(down, 8);
	SetMovingState(Actor::MovingState::EIdle);

	GGame->AddSprite(static_pointer_cast<SpriteComponent>(asc));
	this->AddComponent(asc);

	if (mMyPlayer)
	{
		InputComponentRef playerInputComponent = MakeShared<InputComponent>(shared_from_this());
		playerInputComponent->SetMovingSpeed(300.f);

		playerInputComponent->SetForwardKey(SDL_SCANCODE_D);
		playerInputComponent->SetBackKey(SDL_SCANCODE_A);
		playerInputComponent->SetUpKey(SDL_SCANCODE_W);
		playerInputComponent->SetDownKey(SDL_SCANCODE_S);
		mInputComponent = playerInputComponent;

		this->AddComponent(playerInputComponent);
	}
}

void Player::Die()
{
	if (mInputComponent)
		mInputComponent = nullptr;


	Actor::Die();
}

void Player::UpdateActor(float deltaTime)
{
	if (GetState() == State::EBubble)
	{
		mDeathTimer += deltaTime;

		if (isBubbleTimeOut())
		{
			mDeathTimer = 0.f;
			SetState(State::ETempDie);
		}

	}
	else if (GetState() == State::ETempDie)
	{
		mDeathTimer += deltaTime;

		if (isDead())
		{
			SetState(State::EDead);
		}
	}


	//PlayerToTile Collision
	//for (auto tile : GGame->GetTiles())
	//{
	//	float CollisionX, CollisionY;
	//	//폭탄과 충돌했다면,
	//	if (Intersect(*GetCollider(), *(tile->GetCollider()), &CollisionX, &CollisionY) && CollisionX >=0.1f && CollisionY >= 0.1f)
	//	{
	//		if (GetMovingState() == Actor::MovingState::ERight)
	//		{
	//			Vector2 pos = GetPosition();
	//			pos.x -= CollisionX;
	//			SetPosition(pos);
	//		}
	//		else if (GetMovingState() == Actor::MovingState::ELeft)
	//		{
	//			Vector2 pos = GetPosition();
	//			pos.x += CollisionX;
	//			SetPosition(pos);
	//		}
	//		else if (GetMovingState() == Actor::MovingState::EUp)
	//		{
	//			Vector2 pos = GetPosition();
	//			pos.y += CollisionY;
	//			SetPosition(pos);
	//		}
	//		else if (GetMovingState() == Actor::MovingState::EDown)
	//		{
	//			Vector2 pos = GetPosition();
	//			pos.y -= CollisionY;
	//			SetPosition(pos);
	//		}
	//		break;
	//	}
	//}

	////PlayerToBomb Collision
	//for (auto bomb : GGame->GetBombs())
	//{
	//	float CollisionX, CollisionY;
	//	//폭탄과 충돌했다면,
	//	if (Intersect(*GetCollider(), *(bomb->GetCollider()), &CollisionX, &CollisionY))
	//	{
	//		//폭탄을 처음 놓을 때는 충돌처리 하지 않음
	//		if (bomb->isFirstContact())
	//		{
	//			continue;
	//		}

	//		if (GetMovingState() == Actor::MovingState::ERight)
	//		{
	//			Vector2 pos = GetPosition();
	//			pos.x -= CollisionX;
	//			SetPosition(pos);
	//		}
	//		else if (GetMovingState() == Actor::MovingState::ELeft)
	//		{
	//			Vector2 pos = GetPosition();
	//			pos.x += CollisionX;
	//			SetPosition(pos);
	//		}
	//		else if (GetMovingState() == Actor::MovingState::EUp)
	//		{
	//			Vector2 pos = GetPosition();
	//			pos.y += CollisionY;
	//			SetPosition(pos);
	//		}
	//		else if (GetMovingState() == Actor::MovingState::EDown)
	//		{
	//			Vector2 pos = GetPosition();
	//			pos.y -= CollisionY;
	//			SetPosition(pos);
	//		}
	//		break;
	//	}
	//	//충돌하지 않았을 때,
	//	else
	//	{
	//		
	//		bomb->SetFirstContact();
	//	}

	//}

}

void Player::ActorInput(const class KeyboardState& keyState)
{
}

void Player::SetBubbleToLive()
{
	mDeathTimer = 0.f;
	SetState(State::EActive);
}
