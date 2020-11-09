#pragma once
#include <unordered_map>

#include "../../Renderer/Shader.h"
#include "../../../vendor/glm/glm.hpp"
#include "OpenGLDebugger/OpenglErrorHandler.h"

namespace Hydro
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& location);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		// Set uniforms.
		virtual void SetInt(const std::string& name, int value) override;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) override;
		virtual void SetFloat(const std::string& name, float value) override;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
		virtual void SetMatrix4(const std::string& name, const glm::mat4& value) override;

		int  GetUniforLocation(const std::string& name);

	private:
		uint32_t m_RendererID;
		std::unordered_map<std::string, int> m_UniformLocationCache;

		unsigned int CompileShader(unsigned int type, const std::string &source);
		ShaderProgramSource ParseShader(const std::string& filePath);
		unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
	};
}
