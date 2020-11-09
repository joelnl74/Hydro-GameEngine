#pragma once
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"
#include "Texture.h"
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
		static void StartBatch();
		static void StartNextBatch();

		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color = {1, 1, 1, 1});
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, Texture& texture, const glm::vec4& color = {1, 1, 1, 1});

		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color = {1, 1, 1, 1});
		static void DrawQuad(const glm::mat4& transform, Texture& texture, const glm::vec4& color = {1, 1, 1, 1});

		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color = {1, 1, 1, 1});
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, Texture& texture, float rotation = 0, const glm::vec4& color = {1,1,1,1});
	};
};
