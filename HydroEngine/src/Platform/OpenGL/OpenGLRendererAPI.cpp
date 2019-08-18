#include "OpenGLRendererAPI.h"
#include "OpenGLDebugger/OpenglErrorHandler.h"
namespace Hydro
{
	void OpenGLRendererAPI::SetClearColor(const glm::vec4 & color)
	{
		GLCall(glClearColor(color.r, color.g, color.b, color.a));
	}
	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}

