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
	void ShaderLibarary::Add(const std::string &name, Shader *shader)
	{
		// Retrieve name

		// Add to shaders
		m_Shaders.emplace(name, shader);
	}
	Shader *ShaderLibarary::Load(const std::string & filePath)
	{
		Shader *shader = Shader::Create(filePath);
		Add(filePath, shader);

		return shader;
	}
	Shader *ShaderLibarary::Load(const std::string & name, const std::string & filePath)
	{
		Shader *shader = Shader::Create(filePath);
		Add(name, shader);

		return shader;
	}
	Shader *ShaderLibarary::Get(const std::string & name)
	{
		return m_Shaders[name];
	}
}
