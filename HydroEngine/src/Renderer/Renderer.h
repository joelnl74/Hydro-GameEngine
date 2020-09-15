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

		static const ShaderLibrary& GetShaderLibrary() { return *GetInstance().m_ShaderLibrary; }
		
		inline static Renderer& GetInstance() { return *s_Instance; }
		inline static RendererAPI& GetRendererAPI() {return *GetInstance().s_RenderAPI;}

	private:
		static Renderer* s_Instance;
		static RendererAPI *s_RenderAPI;

		ShaderLibrary *m_ShaderLibrary;
	};
}