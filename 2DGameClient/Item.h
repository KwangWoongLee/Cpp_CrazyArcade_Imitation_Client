#pragma once
#include "stdafx.h"

class Item : public Actor
{
public:
	Item();
	~Item();

	virtual void Init() override;

	void UpdateActor(float deltaTime) override;
	void Die() override;
	virtual void GetActorInfo(Protocol::PActor* actor) override {
		Actor::GetActorInfo(actor);

		mItemType = actor->itemtype();
	};
private:
	Protocol::ItemType mItemType = Protocol::ItemType::ITEM_TYPE_NONE;
};

