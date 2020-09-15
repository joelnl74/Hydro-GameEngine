#include <HydroEngine\src\Core\Assert.h>

#include "VertexArray.h"
#include "../Renderer.h"

#include "../../Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Hydro
{
	IndexBuffer* IndexBuffer::Create(unsigned int* data, unsigned int count)
	{
		switch (Renderer::GetRendererAPI().GetAPI())
		{
		case RendererApiType::None:    return nullptr;
		case RendererApiType::OpenGL:  return new OpenGLIndexBuffer(data, count);
		}

		HY_ASSERT("Unsupported renderer api!");

		return nullptr;
	}
}
