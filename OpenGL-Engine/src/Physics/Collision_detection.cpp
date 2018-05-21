#include "Collision_detection.h"



Collision_detection::Collision_detection()
{
}


Collision_detection::~Collision_detection()
{
}
void Collision_detection::addBoundingBox(glm::vec2 position, glm::vec2 scale)
{
	rect _rec;
	_rec.position = position;
	_rec.scale = scale;

	collisionContainer.push_back(_rec);
}
bool Collision_detection::checkCollision(glm::vec2 position, glm::vec2 scale)
{
	for (auto x : collisionContainer)
	{
		if (position.x < x.position.x + x.scale.x &&
			position.x + scale.x > x.position.x   &&
			position.y < x.position.y + x.scale.y &&
			position.y + scale.y > x.position.y)
		{
			printf("Collision took place! \n");
			return true;
		}
	}
	return false;
}