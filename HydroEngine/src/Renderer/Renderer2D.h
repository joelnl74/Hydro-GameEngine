#pragma once
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

namespace Hydro 
{
	class Renderer2D 
	{
	public:
		static void StartUp();
		static void ShutDown();

		static void BeginScene(glm::mat4x4& viewProjectionMatirx);
		static void EndScene();
		static void Flush();

		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color);
	};
};
