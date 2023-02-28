#pragma once
#include "stdafx.h"

class Component : public enable_shared_from_this<Component>
{
public:
	Component(ActorRef owner, int updateOrder = 100);
	virtual ~Component();

	virtual void Update(float deltaTime);


	int GetUpdateOrder() const { return mUpdateOrder; }

protected:
	weak_ptr<Actor> mOwner;

	int mUpdateOrder;

};

