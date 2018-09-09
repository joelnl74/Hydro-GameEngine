#include "Sprite.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

Sprite::Sprite(float sizeX, float sizeY, float posX, float posY, bool solidSprite)
{
	position.x = posX;
	position.y = posY;

	solid = solidSprite;

	scale.x = sizeX;
	scale.y = sizeY;
}
void Sprite::Update()
{
}
void Sprite::Scale(float x, float y)
{
	scale.x = x;
	scale.y = y;
}
//moves object from current position to a new position by adding a value with the objects position
void Sprite::TransLate(float x, float y)
{
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
void Sprite::setSolid(bool x)
{
	solid = x;
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