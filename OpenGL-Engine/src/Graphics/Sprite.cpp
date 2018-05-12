#include "Sprite.h"
#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"

Sprite::Sprite(float sizeX, float sizeY, float posX, float posY, bool solidSprite)
{
	position.x = posX;
	position.y = posY;

	solid = solidSprite;

	scale.x = sizeX;
	scale.y = sizeY;
}
void Sprite::Rotate(float degrees)
{
	//ToDo Rotate objects
}
void Sprite::Scale(float x, float y, float z)
{
	scale.x = x;
	scale.y = y;
}
void Sprite::TransLate(float x, float y, float z)
{
	//moves object from current position to a new position
	position.x = position.x + x;
	position.y = position.y + y;
}
Sprite::~Sprite()
{
}
void Sprite::setIndex(float x, float y)
{
	offsetX = 1 / x;
	offsetY = 1 / y;
}
void Sprite::setTextureUV(float PosX, float PosY)
{
	indexX = 0;
	indexY = 0;

	float z = offsetX * PosX;
	float w = offsetY * PosY;

	indexX = z;
	indexY = w;
}
const bool Sprite::Sprite_Overlap(Sprite &sprite1, Sprite &sprite2)
{
	// Collision x-axis?
	bool collisionX = sprite1.getPosition().x + sprite1.getScale().x >= sprite2.getPosition().x &&
		sprite2.getPosition().x + sprite2.getScale().x >= sprite1.getPosition().x;
	// Collision y-axis?
	bool collisionY = sprite1.getPosition().y + sprite1.getScale().y >= sprite2.getPosition().y &&
		sprite2.getPosition().y + sprite2.getScale().y >= sprite1.getPosition().y;
	// Collision only if on both axes
	return collisionX && collisionY;
}
