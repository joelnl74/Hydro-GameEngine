#include "VertexArray.h"
#include "../../Platform/OpenGL/OpenGLVertexArray.h"
#include "../Renderer.h"

namespace Hydro
{
	VertexArray* VertexArray::Create(const VertexBuffer* vertexBuffer, const BufferLayout* bufferLayout)
	{
		switch (Renderer::GetRendererAPI().GetAPI())
		{
		case RendererApiType::None:    
			return nullptr;
		case RendererApiType::OpenGL:
			auto vertexArray = new OpenGLVerterArray();
			vertexArray->AddBuffer(vertexBuffer, bufferLayout);

			return vertexArray;
		}

		return nullptr;
	}
}