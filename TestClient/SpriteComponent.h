#pragma once
#include "stdafx.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent(ActorRef owner, int drawOrder);
	~SpriteComponent();
		
	virtual void Draw(SDL_Renderer* renderer, int gameScale = 1);
	
	//Getter, Setter
	virtual void SetTexture(SDL_Texture* texture);

	SDL_Texture* GetTexture() const { return mTexture; }
	int GetTextureHeight() const { return mTextureHeight; }
	int GetTextureWidth() const { return mTextureWidth; }

	int GetDrawOrder() const { return mDrawOrder; }


protected:
	//�׸��� ��������
	int				mDrawOrder;

	//��������Ʈ�� ���ӵ� Texture ����
	SDL_Texture*	mTexture;
	int				mTextureHeight;
	int				mTextureWidth;


};