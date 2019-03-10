#include "Layer.h"
#include <exception>
Layer::Layer(bool static_Layer)
{
	sprites.reserve(MAX_SPRITES);
	//Batch for this layer
	batch = hnew spriteBatch();
	//set static or not
	staticLayer = static_Layer;

	texture->bind();
}
Layer::~Layer()
{
	//clearing the memory
	for (std::vector<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); ++it)
	{
		hdel *it;
	}
	//clear the list
	sprites.clear();
	hdel texture;
}
void Layer::SubmitSprite(Sprite &sprite)
{
	//submit a sprite to renderer to draw
	sprites.push_back(&sprite);
	if (staticLayer)
	{
		SubmitLayer();
	}
}
void Layer::RemoveSprite(Sprite* sprite)
{
	int index = 0;
	for (auto x : sprites)
	{
		if (x == sprite)
		{
			sprites.erase(sprites.begin() + index);
		}
		index++;
	}
}
void Layer::SubmitLayer()
{
	batch->Begin();
	for (auto x : sprites)
	{
		batch->Submit(x);
	}
	batch->End();
}
void Layer::DrawBatch()
{

	if (!staticLayer)
	{
		SubmitLayer();
	}
	batch->Flush();
}
void Layer::DeleteLayer()
{
	for (auto *x : sprites)
	{
		delete x;
	}
	sprites.clear();
}

