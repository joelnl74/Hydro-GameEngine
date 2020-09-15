#include <HydroEngine\src\Core\Assert.h>

#include "VertexBuffer.h"
#include "../Renderer.h"

#include "../../Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Hydro
{
	VertexBuffer* VertexBuffer::Create(void* data, unsigned int size)
	{
		switch (Renderer::GetRendererAPI().GetAPI())
		{
		case RendererApiType::None:    return nullptr;
		case RendererApiType::OpenGL:  return new OpenGLVertexBuffer(data, size);
		}

		HY_ASSERT("Unsupported renderer api!");

		return nullptr;
	}
}