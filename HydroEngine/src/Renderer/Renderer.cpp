#include "Renderer.h"
#include "../Platform/OpenGL/OpenGLRendererAPI.h"


namespace Hydro
{
	RendererApiType RendererAPI::s_API = RendererApiType::OpenGL;

	Renderer* Renderer::s_Instance = new Renderer();
	RendererAPI * Renderer::s_RenderAPI = new OpenGLRendererAPI();

	void Hydro::Renderer::StartUp()
	{
		s_Instance->m_ShaderLibrary = new ShaderLibrary();
	}
	void Hydro::Renderer::ShutDown()
	{
	}
}

