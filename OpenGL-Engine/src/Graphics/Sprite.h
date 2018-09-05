#pragma once
#include "buffer/VertexBuffer.h"
#include "./buffer/VertexBufferLayout.h"
#include "./buffer/IndexBuffer.h"
#include "./buffer/VertexArray.h"
#include "../Component system/Component.h"
#include "Shader.h"
#include "Texture.h"

struct VertexData
{
	glm::vec2 position;
	glm::vec2 uv;
};

class Sprite : Component
{
public:
	Sprite(float sizeX, float sizeY, float posX, float posY, bool solidSprite = false);
	virtual void Update()
	{

	}
	~Sprite();
public:
	void Scale(float x, float y);
	void TransLate(float x, float y);
	void setTextureUV(float PosX, float PosY);
	void setIndex(float x, float y);
	void setSolid(bool x);

	const bool Sprite_Overlap(Sprite &sprite1, Sprite &sprite2);

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

