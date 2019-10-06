#include "Shader.h"
#include "RendererAPI.h"
#include "../Platform/OpenGL/OpenGLShader.h"

namespace Hydro
{
	Shader * Hydro::Shader::Create(const std::string & filepath)
	{
		Shader *result = nullptr;

		switch (RendererAPI::Current())
		{
		case APIType::None: return nullptr;
		case APIType::OpenGL: result = new OpenGLShader(filepath);
		}

		return result;
	}
	void ShaderLibarary::Add(const Shader & shader)
	{
		// m_Shaders.emplace("", shader);
	}
}
