#pragma once
#include "../System.h"

#include "../ComponentContainer.h"
#include "../../Graphics/spriteBatch.h"
class RenderSystem : public System
{
public:
	RenderSystem();
	~RenderSystem();

	bool Init();
	void Update();

	bool update = true;
private:
	ComponentContainer<Sprite> spriteContainer;
	spriteBatch *batch;
	std::vector<Sprite*> m_sprites;
};

