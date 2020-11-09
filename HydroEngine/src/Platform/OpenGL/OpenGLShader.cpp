#include <fstream>
#include <iostream>
#include <sstream>

#include "OpenGLShader.h"
#include "../../vendor/glm/gtc/type_ptr.hpp"

namespace Hydro
{
	OpenGLShader::OpenGLShader(const std::string & filePath)
	{
		ShaderProgramSource source = ParseShader(filePath);
		m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
	}

	OpenGLShader::~OpenGLShader()
	{
		GLCall(glDeleteProgram(m_RendererID));
	}

	unsigned int OpenGLShader::CompileShader(unsigned int type, const std::string & source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		GLCall(glShaderSource(id, 1, &src, nullptr));
		GLCall(glCompileShader(id));

		int result;
		GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
		if (result == GL_FALSE)
		{
			int length;
			GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

			char* message = (char*)malloc(length * sizeof(char));
			GLCall(glGetShaderInfoLog(id, length, &length, message));

			std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertext" : "fragment") << " shader!" << std::endl;
			std::cout << message << std::endl;

			GLCall(glDeleteShader(id));

			return 0;
		}

		return id;
	}
	ShaderProgramSource OpenGLShader::ParseShader(const std::string & filePath)
	{
		std::ifstream stream(filePath);

		if (stream.is_open() == true)
			std::cout << "SHADER FILE FOUND!" << std::endl;
		else
			std::cout << "SHADER FILE NOT FOUND!" << std::endl;

		enum class ShaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		std::string line;
		std::stringstream shaderstream[2];
		ShaderType type = ShaderType::NONE;
		while (std::getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
					type = ShaderType::VERTEX;
				else if (line.find("fragment") != std::string::npos)
					type = ShaderType::FRAGMENT;
			}
			else
			{
				shaderstream[(int)type] << line << '\n';
			}

		}
		return{ shaderstream[0].str(),shaderstream[1].str() };
	}

	unsigned int OpenGLShader::CreateShader(const std::string & vertexShader, const std::string & fragmentShader)
	{

		unsigned int program = glCreateProgram();
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		GLCall(glAttachShader(program, vs));
		GLCall(glAttachShader(program, fs));

		GLCall(glLinkProgram(program));
		GLCall(glValidateProgram(program));

		GLCall(glDeleteShader(vs));
		GLCall(glDeleteShader(fs));

		return program;
	}

	//bind the shader program
	void OpenGLShader::Bind() const
	{
		GLCall(glUseProgram(m_RendererID));
	}
	
	//unbind the shader program
	void OpenGLShader::UnBind() const
	{
		GLCall(glUseProgram(0));
	}

	void OpenGLShader::SetInt(const std::string& name, int value)
	{
		GLint location = GetUniforLocation(name);
		glUniform1i(location, value);
	}

	void OpenGLShader::SetIntArray(const std::string& name, int* values, uint32_t count)
	{
		GLint location = GetUniforLocation(name);
		glUniform1iv(location, count, values);
	}

	void OpenGLShader::SetFloat(const std::string& name, float value)
	{
		GLint location = GetUniforLocation(name);
		glUniform1f(location, value);
	}

	void OpenGLShader::SetFloat3(const std::string& name, const glm::vec3& value)
	{
		GLint location = GetUniforLocation(name);
		glUniform3f(location, value.x, value.y, value.z);
	}

	void OpenGLShader::SetFloat4(const std::string& name, const glm::vec4& value)
	{
		GLint location = GetUniforLocation(name);
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::SetMatrix4(const std::string& name, const glm::mat4& value)
	{
		GLint location = GetUniforLocation(name);
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}

	int OpenGLShader::GetUniforLocation(const std::string & name)
	{
		if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
			return m_UniformLocationCache[name];
		GLCall(int  location = glGetUniformLocation(m_RendererID, name.c_str()));
		if (location == -1)
			std::cout << "Warning: uniform " << name << "doesn't exist" << std::endl;

		m_UniformLocationCache[name] = location;
		return location;
	}
}

