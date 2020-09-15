#include "VertexArray.h"
#include "../../Platform/OpenGL/OpenGLIndexBuffer.h"
#include "../Renderer.h"

namespace Hydro
{
	IndexBuffer* IndexBuffer::Create(unsigned int* data, unsigned int count)
	{
		switch (Renderer::GetRendererAPI().GetAPI())
		{
		case RendererApiType::None:    return nullptr;
		case RendererApiType::OpenGL:  return new OpenGLIndexBuffer(data, count);
		}

		return nullptr;
	}
}