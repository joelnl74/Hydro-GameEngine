#pragma once
#include <vector>
#include "../spriteBatch.h"
#include "../Sprite.h"
class Layer
{
public:
	Layer(bool static_Layer);
	~Layer();
	void submitSprite(Sprite &sprite);
	void drawBatch();
	void submitLayer();
	inline const std::vector<Sprite*> &returnSprites() { return sprites; }
	void removeSprite(Sprite *sprite);
	Sprite &returnSprite(float mouseX, float mouseY);
private:
	spriteBatch* batch;
	std::vector<Sprite*> sprites;
	bool staticLayer;
};

