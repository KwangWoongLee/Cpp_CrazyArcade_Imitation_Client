#pragma once
#include "stdafx.h"
#include "Protocol.pb.h"

class Actor : public enable_shared_from_this<Actor>
{
public:
	enum class State
	{
		EActive,
		EBubble,
		ETempDie,
		EDead,
		WANT_DIE,
	};

	enum class MovingState
	{
		ENone,
		EIdle,
		ELeft,
		ERight,
		EUp,
		EDown,
		EStop
	};

public:
	Actor(uint64 serverId, string name, Vector2 pos);
	virtual ~Actor();

	virtual void Init() {};
	virtual void ActorInput(const class KeyboardState& keyState);

	virtual void UpdateActor(float deltaTime) = 0;
	virtual void Die() = 0;;


	//Game Update에서 호출하는 Update(UpdateGame -> 각 Actor Update)
	void Update(float deltaTime);
	
	// Actor에 붙어있는 모든 Component들 업데이트
	void UpdateComponents(float deltaTime);

	void WantDie();

	
	void ProcessInput(const class KeyboardState& keyState);


	//Getter , Setter
	State	GetState() const { return mState; }
	void	SetState(State state) { mState = state; }

	MovingState	GetMovingState() const { return mMovingState; }
	void		SetMovingState(MovingState state, bool flag = false);

	float	GetScale() const		{ return mScale; }
	void	SetScale(float scale)	{ mScale = scale; }

	Vector2 GetPosition() const { return mPosition; }
	void	SetPosition(const Vector2& inPosition) { mPosition = inPosition; }

	//Component 추가 및 삭제
	void AddComponent(ComponentRef inComponent);
	void RemoveComponent(ComponentRef inComponent);

	uint64 GetServerId() const {
		return mServerId;
	}
	void SetServerId(uint64 serverId) { mServerId = serverId; }

protected:
	Protocol::ActorType mType = Protocol::ActorType::ACTOR_TYPE_NONE;
	Protocol::PlayerAction mAction = Protocol::PlayerAction::PLAYER_ACTION_NONE;
	string mName;
	
private:
	State	mState;
	MovingState	mMovingState;
	Vector2 mPosition;
	float	mScale;
	uint64 mServerId{};


	//actor 객체가 소유한 component를 담는 변수
	Vector<ComponentRef> mComponents;

};

