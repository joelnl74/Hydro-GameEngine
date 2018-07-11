#include "Layer.h"
#include <exception>
Layer::Layer(bool static_Layer)
{
	//Batch for this layer
	batch = new spriteBatch();
	//set static or not
	staticLayer = static_Layer;
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
	delete texture;
}
void Layer::submitSprite(Sprite &sprite)
{
	//submit a sprite to renderer to draw
	sprites.push_back(&sprite);
	if (staticLayer)
	{
		submitLayer();
	}
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
void Layer::submitLayer()
{
	batch->begin();
	for (auto x : sprites)
	{
		batch->submit(x);
	}
	batch->end();
}
void Layer::drawBatch()
{
	//draw the layer onto the screen
	texture->bind();
	if (!staticLayer)
	{
		submitLayer();
	}
	batch->flush();
	texture->unBind();

}
Sprite* Layer::returnSprite(float mouseX, float mouseY)
{
	//return a sprite based on position of the mouse
		for (auto x : sprites)
		{
			if (mouseX < x->getPosition().x + x->getScale().x && mouseX >= x->getPosition().x
				&& mouseY < x->getPosition().y + x->getScale().y && mouseY >= x->getPosition().y)
			{
				return x;
				break;
			}
		}
		printf("no sprite found\n");
		return nullptr;
}	

