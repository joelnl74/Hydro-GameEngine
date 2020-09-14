#include "Shader.h"
#include "RendererAPI.h"
#include "../Platform/OpenGL/OpenGLShader.h"

namespace Hydro
{
	Shader * Hydro::Shader::Create(const std::string & filepath)
	{
		Shader *result = nullptr;

		switch (RendererAPI::GetAPI())
		{
		case RendererApiType::None: return nullptr;
		case RendererApiType::OpenGL: result = new OpenGLShader(filepath);
		}

		return result;
	}
	void ShaderLibrary::Add(const std::string &name, Shader *shader)
	{
		// Add to shaders
		m_Shaders.emplace(name, shader);
	}
	Shader *ShaderLibrary::Load(const std::string & filePath)
	{
		Shader *shader = Shader::Create(filePath);
		Add(filePath, shader);

		return shader;
	}
	Shader *ShaderLibrary::Load(const std::string & name, const std::string & filePath)
	{
		Shader *shader = Shader::Create(filePath);
		Add(name, shader);

		return shader;
	}
	Shader *ShaderLibrary::Get(const std::string & name)
	{
		return m_Shaders[name];
	}
}
