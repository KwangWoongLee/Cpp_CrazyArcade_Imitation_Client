#include "stdafx.h"
#include "Item.h"

Item::Item()
{
	SetScale(0.4f);
}

Item::~Item()
{
}

void Item::UpdateActor(float deltaTime)
{
}

void Item::Die()
{
	Actor::Die();
}

void Item::Init()
{
	auto anim = std::make_shared<AnimationComponent>(shared_from_this(), 10);
	SDL_Texture* item = nullptr;
	switch (mItemType)
	{
	case Protocol::ITEM_TYPE_NONE:
		break;
	case Protocol::ITEM_TYPE_SHOE:
		item = gGame->GetTexture("Assets/item_shoe.bmp");
		break;
	case Protocol::ITEM_TYPE_BOMB:
		item = gGame->GetTexture("Assets/item_bomb.bmp");
		break;
	default:
		break;
	}

	anim->SetAnimTexture(item, 6);
	gGame->AddSprite(static_pointer_cast<SpriteComponent>(anim));
	AddComponent(anim);
}

