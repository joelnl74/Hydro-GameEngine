#pragma once
#include <vector>
#include "spriteBatch.h"
#include "Sprite.h"
class Layer
{
public:
	Layer();
	~Layer();
	void submitSprite(Sprite &sprite);
	void drawBatch();
private:
	spriteBatch * batch;
	std::vector<Sprite> sprites;
};

