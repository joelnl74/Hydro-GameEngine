#pragma once
#include "Camera.h"
#include "RenderCommand.h"
#include "Shader.h"
#include "SpriteBatch.h"

namespace Hydro
{
	class Renderer
	{
	public:
		static void Init();

		static void BeginScene(Camera& camera);
		static void EndScene();

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
		static void Submit3D(const Shader &shader, const glm::mat4& transform = glm::mat4(1.0f));
		static void Submit2D(const Shader &shader, const SpriteBatch &spriteBatch);
	};
}