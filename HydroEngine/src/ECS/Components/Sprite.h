#pragma once
#include "RenderAble.h"
#include "../../vendor/glm/common.hpp"
#include "../ECS_Engine.h"
struct VertexData
{
	glm::vec2 position;
	glm::vec2 uv;
};

class Sprite : public RenderAble
{
public:
	Sprite(Entity e)
	{
		entity_ID = e.entityID;
		transform = *ECS_Engine::GetInstance().m_EntityManager->GetEntityByID(entity_ID).transform;

		setIndex(4, 4);
		setTextureUV(0, 0);
	}
	~Sprite()
	{
	}
	void Scale(float x, float y)
	{
		transform.scale.x = x;
		transform.scale.y = y;
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

	inline const void setPosition(float x, float y) { transform.position.x = x, transform.position.y = y; }
	inline const glm::vec2 getPosition() { return transform.position; }
	inline const glm::vec2 getScale() { return  transform.scale; }
	inline const glm::vec2 getUV() { return  glm::vec2(indexX, indexY); }

	//TODO change this and setTextureuv and setIndex partially to the texture class so we dont save it every sprite
	float offsetX;
	float offsetY;

private:
	Transform transform;

	int textureID = 0;

	float indexX;
	float indexY;
};

