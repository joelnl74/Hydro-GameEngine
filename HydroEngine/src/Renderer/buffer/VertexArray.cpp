#include <HydroEngine\src\Core\Assert.h>

#include "VertexArray.h"
#include "../Renderer.h"

#include "../../Platform/OpenGL/OpenGLVertexArray.h"

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

		HY_ASSERT("Unsupported renderer api!");

		return nullptr;
	}
}
