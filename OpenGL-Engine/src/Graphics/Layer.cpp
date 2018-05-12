#include "Layer.h"



Layer::Layer()
{
	sprites.reserve(20024);
	batch = new spriteBatch();
}


Layer::~Layer()
{
	for (std::vector<Sprite*>::iterator it = sprites.begin(); it != sprites.end(); ++it)
	{
		delete(*it);
	}
	sprites.clear();
}
void Layer::submitSprite(Sprite &sprite)
{
	sprites.push_back(&sprite);
}
void Layer::drawBatch()
{
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
	for (auto x : sprites)
	{
		if (mouseX < x->getPosition().x + x->getScale().x && mouseX >= x->getPosition().x
			&& mouseY < x->getPosition().y + x->getScale().y && mouseY >= x->getPosition().y)
		{
			return *x;
		}
	}
}
