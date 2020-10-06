#include "OpenGLRendererAPI.h"
#include "OpenGLDebugger/OpenglErrorHandler.h"
namespace Hydro
{

	void OpenGLRendererAPI::Init()
	{

	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		GLCall(glClearColor(color.r, color.g, color.b, color.a));
	}

	void OpenGLRendererAPI::Draw2DIndexed(VertexArray* VertexArray, uint32_t indexCount)
	{
		uint32_t count = indexCount ? indexCount : VertexArray->GetIndexBuffer()->GetCount();
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGLRendererAPI::Draw3D()
	{
	}

	void OpenGLRendererAPI::Draw3DIndexed()
	{
	}

	void OpenGLRendererAPI::DrawLine()
	{
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}

