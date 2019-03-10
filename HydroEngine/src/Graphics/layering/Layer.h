#pragma once
#include <vector>
#include "../spriteBatch.h"
#include "../../ECS/Components/Sprite.h"
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
private:
	//TODO Change this to the resource manager and hold a reference to the texture instead
	Texture * texture = hnew Texture("Resources/textures/Tiles.png");
	spriteBatch* batch;
	std::vector<Sprite*> sprites;
	bool staticLayer;
};

