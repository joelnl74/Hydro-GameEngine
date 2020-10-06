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

		// static const ShaderLibrary* GetShaderLibrary() { return m_ShaderLibrary; }
		
		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		// static ShaderLibrary *m_ShaderLibrary;
	};
}
