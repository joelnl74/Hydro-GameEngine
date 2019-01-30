#pragma once
#include "RenderAble.h"
#include "../../vendor/glm/common.hpp"

struct VertexData
{
	glm::vec2 position;
	glm::vec2 uv;
};

class Sprite : public RenderAble
{
public:
	Sprite(float sizeX, float sizeY, float posX, float posY, bool solidSprite = false);
	~Sprite();
public:
	void Scale(float x, float y);
	void TransLate(float x, float y);
	void setTextureUV(float PosX, float PosY);
	void setIndex(float x, float y);
	void setSolid(bool x);

	inline const void setPosition(float x, float y) { position.x = x, position.y = y; }
	inline const glm::vec2 getPosition() { return  position; }
	inline const glm::vec2 getScale() { return  scale; }
	inline const glm::vec2 getUV() { return  glm::vec2(indexX, indexY); }

	//TODO change this and setTextureuv and setIndex partially to the texture class so we dont save it every sprite
	float offsetX;
	float offsetY;

	int textureId = 0;

private:

	glm::vec2 position;
	glm::vec2 scale;

	float indexX;
	float indexY;

	bool solid;
};

