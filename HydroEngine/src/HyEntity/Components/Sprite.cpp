#include "Sprite.h"

namespace Hydro
{
	Sprite::Sprite()
	{
		setIndex(4, 4);
		setTextureUV(0, 0);
	}

	Sprite::~Sprite()
	{
	}

	void Sprite::Start()
	{
	}

	void Sprite::Update()
	{
	}

	//Set index of the texture atlass
	void Sprite::setIndex(float x, float y)
	{
		offsetX = 1 / x;
		offsetY = 1 / y;
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
}