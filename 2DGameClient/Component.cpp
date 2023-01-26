#include "stdafx.h"

Component::Component(ActorRef owner, int updateOrder)
	:mOwner(owner)
	,mUpdateOrder(updateOrder)
{
}

Component::~Component()
{
}

void Component::ProcessInput(const class KeyboardState& keyState)
{
}

void Component::Update(float deltaTime)
{
}
