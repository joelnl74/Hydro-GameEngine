#include "Sprite.h"
#include "../../Graphics/RenderManager.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

Sprite::Sprite(float sizeX, float sizeY, float posX, float posY, bool solidSprite)
{
	position.x = posX;
	position.y = posY;

	solid = solidSprite;

	scale.x = sizeX;
	scale.y = sizeY;

	//TODO MAKES THIS INTO A SYSTEM NOW IT ADD ITSELF TO THE RENDERMANAGER YOU DONT WANT THIS :P
	RenderManager::GetInstance()._layerManager->getLayer(0)->SubmitSprite(*this);
}
void Sprite::Update()
{
}
//TODO CHANGE TRANSLATION SCALING AND OTHER MOVEMENT STUFF TO THE TRANSFORM COMPONENT
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
//Set index of the texture atlass
void Sprite::setIndex(float x, float y)
{
	offsetX = 1 / x;
	offsetY = 1 / y;
}
//Set object to solid
void Sprite::setSolid(bool x)
{
	solid = x;
}
//Set the texture uv
void Sprite::setTextureUV(float PosX, float PosY)
{
	indexX = 0;
	indexY = 0;

	float z = offsetX * PosX;
	float w = offsetY * PosY;

	indexX = z;
	indexY = w;
}