#include "Layer.h"



Layer::Layer()
{
	sprites.reserve(20024);
	batch = new spriteBatch();
}


Layer::~Layer()
{
}
void Layer::submitSprite(Sprite &sprite)
{
	sprites.push_back(sprite);
}
void Layer::drawBatch()
{
	batch->begin();
	for (auto x : sprites)
	{
		batch->submit(&x);
	}
	batch->end();
	batch->flush();
}
