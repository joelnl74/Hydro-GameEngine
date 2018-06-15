#pragma once
#include <vector>
#include "../spriteBatch.h"
#include "../Sprite.h"
class Layer
{
public:
	Layer();
	~Layer();
	void submitSprite(Sprite &sprite);
	void drawBatch();
	inline const std::vector<Sprite*> &returnSprites() { return sprites; }
	Sprite &returnSprite(float mouseX, float mouseY);
private:
	spriteBatch* batch;
	std::vector<Sprite*> sprites;
};

