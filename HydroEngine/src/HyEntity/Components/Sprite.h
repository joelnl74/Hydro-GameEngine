#pragma once
#include "../Component.h"
#include "../../vendor/glm/common.hpp"
struct VertexData
{
	glm::vec2 position;
	glm::vec2 uv;
};

class Sprite : public Component
{
public:
	Sprite()
	{
		setIndex(4, 4);
		setTextureUV(0, 0);
	}
	~Sprite()
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

	inline const glm::vec2 getPosition() const { return glm::vec2(indexX, indexY); }
	inline const glm::vec2 getScale()	 const { return glm::vec2(indexX, indexY); }
	inline const glm::vec2 getUV()		 const { return glm::vec2(indexX, indexY); }

	//TODO change this and setTextureuv and setIndex partially to the texture class so we dont save it every sprite
	float offsetX;
	float offsetY;

private:
	int textureID = 0;

	float indexX;
	float indexY;
};

