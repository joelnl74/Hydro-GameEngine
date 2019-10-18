#pragma once
#include "Camera.h"
#include "Shader.h"

#include "RendererAPI.h"

class ShaderLibrary;

namespace Hydro
{
	class Renderer
	{
	public:
		static void StartUp();
		static void ShutDown();

		static void BeginScene(Camera& camera);
		static void EndScene();

		static const ShaderLibrary& GetShaderLibrary() { return *GetInstance().m_ShaderLibrary; }
		
		static void Submit3D(const Shader &shader, const glm::mat4& transform = glm::mat4(1.0f));

		inline static Renderer& GetInstance() { return *s_Instance; }
		inline static RendererAPI& GetAPI() {return *GetInstance().s_RenderAPI;}

	private:
		static Renderer* s_Instance;
		static RendererAPI *s_RenderAPI;

		ShaderLibrary *m_ShaderLibrary;
	};
}