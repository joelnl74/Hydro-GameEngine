#include <HydroEngine\src\Core\Assert.h>

#include "VertexBuffer.h"
#include "../Renderer.h"

#include "../../Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Hydro
{
	VertexBuffer* VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetRendererAPI().GetAPI())
		{
		case RendererApiType::None:    return nullptr;
		case RendererApiType::OpenGL:  return new OpenGLVertexBuffer(size);
		}

		HY_ASSERT("Unsupported renderer api!");

		return nullptr;
	}

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetRendererAPI().GetAPI())
		{
		case RendererApiType::None:    return nullptr;
		case RendererApiType::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
		}

		HY_ASSERT("Unsupported renderer api!");

		return nullptr;
	}
}