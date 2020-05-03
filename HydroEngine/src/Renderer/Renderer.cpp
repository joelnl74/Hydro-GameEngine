#include "Renderer.h"
#include "../Platform/OpenGL/OpenGLRendererAPI.h"


namespace Hydro
{
	APIType RendererAPI::s_API = APIType::OpenGL;

	Renderer* Renderer::s_Instance = new Renderer();
	RendererAPI * Renderer::s_RenderAPI = new OpenGLRendererAPI();

	void Hydro::Renderer::StartUp()
	{
		s_Instance->m_ShaderLibrary = new ShaderLibrary();
	}
	void Hydro::Renderer::ShutDown()
	{
	}

	void Hydro::Renderer::BeginScene(Camera & camera)
	{
	}

	void Hydro::Renderer::EndScene()
	{
	}

	void Hydro::Renderer::Submit3D(const Shader & shader, const glm::mat4 & transform)
	{
	}
}

