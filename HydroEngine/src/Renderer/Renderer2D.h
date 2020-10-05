#pragma once
#include "../../vendor/glm/glm.hpp"

namespace Hydro 
{
	class Renderer2d 
	{
	public:
		static void StartUp();
		static void ShutDown();

		static void BeginScene(glm::mat4x4& viewProjectionMatirx);
		static void EndScene();

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
	};
};
