#pragma once
#include "../Component.h"
#include "../../vendor/glm/common.hpp"

namespace Hydro
{
	struct VertexData
	{
		glm::vec2 position;
		glm::vec2 uv;
	};

	class Sprite : public Component
	{
	public:
		Sprite();
		~Sprite();

		void Start();
		void Update();

		//Set index of the texture atlass
		void Sprite::setIndex(float x, float y);

		//Set the texture uv
		void Sprite::setTextureUV(float PosX, float PosY);

		inline const glm::vec2 getPosition() const { return transform->position; }
		inline const glm::vec2 getScale()	 const { return transform->scale; }
		inline const glm::vec2 getUV()		 const { return  glm::vec2(indexX, indexY); }

		//TODO change this and setTextureuv and setIndex partially to the texture class so we dont save it every sprite
		float offsetX;
		float offsetY;

	private:
		int textureID = 0;

		float indexX;
		float indexY;
	};
}
