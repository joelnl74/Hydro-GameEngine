#include "Layer.h"

Layer::Layer()
{
	//Max size of a sprite batch
	sprites.reserve(20024);
	//Batch for this layer
	batch = new spriteBatch();
}
Layer::~Layer()
{
	//clearing the memory
	for (std::vector<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); ++it)
	{
		delete *it;
	}
	//clear the list
	sprites.clear();
}
void Layer::submitSprite(Sprite &sprite)
{
	//submit a sprite to renderer to draw
	sprites.push_back(&sprite);
}
void Layer::removeSprite(Sprite* sprite)
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
void Layer::drawBatch()
{
	//draw the layer onto the screen
	batch->begin();
	for (auto x : sprites)
	{
		batch->submit(x);
	}
	batch->end();
	batch->flush();
}
Sprite& Layer::returnSprite(float mouseX, float mouseY)
{
	//return a sprite based on position of the mouse
	for (auto x : sprites)
	{
		if (mouseX < x->getPosition().x + x->getScale().x && mouseX >= x->getPosition().x
			&& mouseY < x->getPosition().y + x->getScale().y && mouseY >= x->getPosition().y)
		{
			return *x;
		}
	}
}
