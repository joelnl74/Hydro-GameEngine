#include "Renderer.h"

#include "RenderCommand.h"
#include "Renderer2D.h"

namespace Hydro
{
	void Hydro::Renderer::StartUp()
	{
		RenderCommand::Init();
		Renderer2D::StartUp();

		// m_ShaderLibrary = new ShaderLibrary();
	}
	void Hydro::Renderer::ShutDown()
	{
		// delete m_ShaderLibrary;
	}
}

