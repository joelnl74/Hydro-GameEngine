#pragma once
#include "../../vendor/glm/glm.hpp"
#include <string>
#include <unordered_map>
#include <cstdint>
namespace Hydro
{
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};

	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) = 0;
		virtual void SetMatrix4(const std::string& name, const glm::mat4& value) = 0;

		static Shader* Create(const std::string &filepath);
	};

	class ShaderLibrary
	{
	public:
		void Add(const std::string &name, Shader *shader);

		Shader *Load(const std::string &filePath);
		Shader *Load(const std::string &name, const std::string &filePath);
		Shader *Get(const std::string &name);

	private:
		std::unordered_map<std::string, Shader*> m_Shaders;
	};
}
