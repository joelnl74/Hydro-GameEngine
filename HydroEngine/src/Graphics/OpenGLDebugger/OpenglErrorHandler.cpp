#include "OpenglErrorHandler.h"
#include <iostream>

namespace Hydro
{
	const char * GetGLErrorStr(GLenum err)
	{
		//ERROR CAN BE ADDED HERE IN THE FUTURE
		switch (err)
		{
		case GL_NO_ERROR:          return "No error";
		case GL_INVALID_ENUM:      return "Invalid enum";
		case GL_INVALID_VALUE:     return "Invalid value";
		case GL_INVALID_OPERATION: return "Invalid operation";
		case GL_STACK_OVERFLOW:    return "Stack overflow";
		case GL_STACK_UNDERFLOW:   return "Stack underflow";
		case GL_OUT_OF_MEMORY:     return "Out of memory";
		default:                   return "Unknown error";
		}
	}

	void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}
	bool GLLogCall(const char* function, const char* file, int line)
	{

		while (GLenum error = glGetError())
		{
			std::cout << "[OpenGL Error] (" << error << ":" << GetGLErrorStr(error) << "): " << function << " " << file << ":" << line << " " << std::endl;
			return false;
		}
		return true;
	}
}
