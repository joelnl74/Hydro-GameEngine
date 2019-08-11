#pragma once
#include <unordered_map>

#include "../../Graphics/Shader.h"
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/type_ptr.inl"
#include "../../Graphics//OpenGLDebugger/OpenglErrorHandler.h"

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
		void setUniform4f(const std::string& name, float f0, float f1, float f2, float f3); //vec4 float
		void setUniform1f(const std::string& name, float value);                            //vec1 float
		void setUniform1i(const std::string& name, int value);                              //vec1 int
		void SetMatrix4(const std::string& name, glm::mat4 &matrix);                        //matrix4f view * model
		void UniformMatrix4fv(const std::string& name, glm::mat4 &matrix);                  //set mat4 
		void setVec2(const std::string& name, glm::fvec2 vector2);                          //set vec2 of floats
		void setVec3(const std::string& name, glm::fvec3 vector3);                          //set vec3 of floats
		int GetUniforLocation(const std::string& name);                                     //Gets the location of the uniform

	private:
		uint32_t m_RendererID;
		std::unordered_map<std::string, int> m_UniformLocationCache;

		unsigned int CompileShader(unsigned int type, const std::string &source);
		ShaderProgramSource ParseShader(const std::string& filePath);
		unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
	};
}
