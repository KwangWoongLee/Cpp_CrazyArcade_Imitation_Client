#pragma once
#include "stdafx.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent(ActorRef owner, int drawOrder);
	~SpriteComponent();
		
	virtual void Draw(SDL_Renderer* renderer, int gameScale = 1);
	
	int GetTextureHeight() const { return mTextureHeight; }
	int GetTextureWidth() const { return mTextureWidth; }

	int GetDrawOrder() const { return mDrawOrder; }


protected:
	//�׸��� ��������
	int				mDrawOrder;
	int				mTextureHeight;
	int				mTextureWidth;


};
