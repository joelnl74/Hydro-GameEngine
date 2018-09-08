#pragma once
#include <vector>
#include "../spriteBatch.h"
#include "../../Components/Sprite.h"
class Layer
{
public:
	Layer(bool static_Layer);
	~Layer();
	void SubmitSprite(Sprite &sprite);
	void DrawBatch();
	void SubmitLayer();
	inline const std::vector<Sprite*> &ReturnSprites() { return sprites; }
	void RemoveSprite(Sprite *sprite);
	void DeleteLayer();
	Sprite *ReturnSprite(float mouseX, float mouseY);
private:
	//create a texture tempfix need to create a rescourcemanager for this
	Texture * texture = new Texture("res/textures/Tiles.png");
	spriteBatch* batch;
	std::vector<Sprite*> sprites;
	bool staticLayer;
};

