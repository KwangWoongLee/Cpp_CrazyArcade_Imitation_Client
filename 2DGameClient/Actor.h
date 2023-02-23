#pragma once
#include "stdafx.h"
#include "Proto/protocol.pb.h"

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
	Actor();
	virtual ~Actor();

	virtual void UpdateActor(float deltaTime) = 0;
	virtual void Die() = 0;;

	virtual void Init() {};
	virtual void GetActorInfo(Protocol::PActor* actor) {
		mServerId = actor->id();
		mType = actor->type();

		mPosition.x = actor->position().x();
		mPosition.y = actor->position().y();
	};

	virtual void MoveNextPosition(Protocol::Action action);

	//Game Update���� ȣ���ϴ� Update(UpdateGame -> �� Actor Update)
	void Update(float deltaTime);
	
	// Actor�� �پ��ִ� ��� Component�� ������Ʈ
	void UpdateComponents(float deltaTime);

	void WantDie();



	//Getter , Setter
	State	GetState() const { return mState; }
	void	SetState(State state) { mState = state; }

	MovingState	GetMovingState() const { return mMovingState; }
	void		SetMovingState(MovingState state, bool flag = false);

	float	GetScale() const		{ return mScale; }
	void	SetScale(float scale)	{ mScale = scale; }

	Vector2 GetPosition() const { return mPosition; }
	void	SetPosition(const Vector2& inPosition) { mPosition = inPosition; }

	float	GetSpeed() const { return mSpeed; }
	void	SetSpeed(float speed) { mSpeed = speed; }

	//Component �߰� �� ����
	void AddComponent(ComponentRef inComponent);
	void RemoveComponent(ComponentRef inComponent);

	uint64 GetServerId() const {
		return mServerId;
	}
	void SetServerId(uint64 serverId) { mServerId = serverId; }

	bool mDirtyFlag = false;

protected:
	Protocol::ActorType mType = Protocol::ActorType::ACTOR_TYPE_NONE;
	
private:
	State	mState;
	MovingState	mMovingState;
	Vector2 mPosition;
	float	mScale;
	float	mSpeed;
	uint64 mServerId{};


	//actor ��ü�� ������ component�� ��� ����
	std::vector<ComponentRef> mComponents;

};

