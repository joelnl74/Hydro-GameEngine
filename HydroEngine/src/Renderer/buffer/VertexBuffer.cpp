#include "VertexBuffer.h"
#include "../../Platform/OpenGL/OpenGLVertexBuffer.h"
#include "../Renderer.h"

namespace Hydro
{
	VertexBuffer* VertexBuffer::Create(void* data, unsigned int size)
	{
		switch (Renderer::GetRendererAPI().GetAPI())
		{
		case RendererApiType::None:    return nullptr;
		case RendererApiType::OpenGL:  return new OpenGLVertexBuffer(data, size);
		}

		return nullptr;
	}
}