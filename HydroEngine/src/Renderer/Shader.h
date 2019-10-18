#pragma once
#include "../vendor/glm/glm.hpp"
#include <string>
#include <unordered_map>

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

		// Make abstract way of settting data in a shader
		virtual void SetMatrix4(const std::string& name, glm::mat4 &matrix) = 0;

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
