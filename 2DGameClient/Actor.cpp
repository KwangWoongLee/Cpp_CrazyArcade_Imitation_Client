#include "stdafx.h"

Actor::Actor()
	:mState(State::EActive)
	,mMovingState(MovingState::ENone)
	, mScale(1.0f)
	, mSpeed(10.0f)
{
}

Actor::~Actor()
{
	for (auto component : mComponents)
	{
		auto sprite = dynamic_pointer_cast<SpriteComponent>(component);
		if (sprite != nullptr)
			gGame->RemoveSprite(sprite);
	}

	mComponents.clear();
}

void Actor::MoveNextPosition(Protocol::Action action)
{
	auto actorSpeed = GetSpeed();

	float hopeX = GetPosition().x;
	float hopeY = GetPosition().y;

	switch (action)
	{
	case Protocol::Action::ACTION_DOWN:
		SetMovingState(MovingState::EDown);
		hopeY +=  actorSpeed * 1.f;
		break;
	case Protocol::Action::ACTION_UP:
		SetMovingState(MovingState::EUp);
		hopeY -= actorSpeed * 1.f;
		break;
	case Protocol::Action::ACTION_LEFT:
		SetMovingState(MovingState::ELeft);
		hopeX -= actorSpeed * 1.f;
		break;
	case Protocol::Action::ACTION_RIGHT:
		SetMovingState(MovingState::ERight);
		hopeX += actorSpeed * 1.f;
		break;
	default:
		SetMovingState(MovingState::EStop);
		break;
	}

	if (hopeX == GetPosition().x && hopeY == GetPosition().y)
		return;


	mDirtyFlag = true;
	SetPosition(Vector2(hopeX, hopeY));
}

void Actor::Update(float deltaTime)
{
	ASSERT_CRASH(mState != State::EDead)
	
	UpdateComponents(deltaTime);
	UpdateActor(deltaTime);

	mDirtyFlag = false;
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
void Actor::SetMovingState(MovingState state, bool flag)
{
	if (mMovingState == state)
	{
		return;
	}
	
	mDirtyFlag = true;
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
