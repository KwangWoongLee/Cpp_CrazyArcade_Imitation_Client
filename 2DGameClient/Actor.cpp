#include "stdafx.h"
#include "World.h"

Actor::Actor(uint64 serverId, string name, Vector2 pos)
	:mState(State::EActive)
	,mMovingState(MovingState::ENone)
	, mPosition(pos)
	, mScale(1.0f)
	,mServerId(serverId)
	, mName(name)
{
}

Actor::~Actor()
{
	mComponents.clear();
}

void Actor::Update(float deltaTime)
{
	ASSERT_CRASH(mState != State::EDead)
	
	UpdateComponents(deltaTime);
	UpdateActor(deltaTime);
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto component : mComponents)
	{
		component->Update(deltaTime);
	}
}

void Actor::WantDie()
{
	mState = State::WANT_DIE;
}

void Actor::Die()
{

}

void Actor::ProcessInput(const class KeyboardState& keyState)
{
	if (mState == State::EActive)
	{
		for (auto comp : mComponents)
		{
			comp->ProcessInput(keyState);
		}

		ActorInput(keyState);
	}
}

void Actor::ActorInput(const class KeyboardState& keyState)
{
}

void Actor::SetMovingState(MovingState state, bool flag)
{
	mMovingState = state;
}

void Actor::AddComponent(ComponentRef component)
{
	//Component 그리기 순서를 위한 순서 정렬
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (;
		iter != mComponents.end();
		++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	mComponents.insert(iter , component);
}

void Actor::RemoveComponent(ComponentRef component)
{
	mComponents.erase(remove(mComponents.begin(), mComponents.end(), component));
}
