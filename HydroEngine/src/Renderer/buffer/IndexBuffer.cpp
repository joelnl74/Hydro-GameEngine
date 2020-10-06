#include <HydroEngine\src\Core\Assert.h>

#include "VertexArray.h"
#include "../Renderer.h"

#include "../../Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Hydro
{
	IndexBuffer* IndexBuffer::Create(unsigned int* data, unsigned int count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLIndexBuffer(data, count);
		}

		HY_ASSERT("Unsupported renderer api!");

		return nullptr;
	}
}
