#pragma once
#include "../System.h"

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
	spriteBatch *batch;
	std::vector<Sprite*> m_sprites;
};

