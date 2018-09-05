#pragma once
#include <vector>
#include "../spriteBatch.h"
#include "../../Components/Sprite.h"
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
	Sprite *returnSprite(float mouseX, float mouseY);
private:
	//create a texture tempfix need to create a rescourcemanager for this
	Texture * texture = new Texture("res/textures/Tiles.png");
	spriteBatch* batch;
	std::vector<Sprite*> sprites;
	bool staticLayer;
};

