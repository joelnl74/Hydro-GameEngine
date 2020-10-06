#include <HydroEngine\src\Core\Assert.h>

#include "VertexArray.h"
#include "../Renderer.h"

#include "../../Platform/OpenGL/OpenGLVertexArray.h"

namespace Hydro
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
		}

		HY_ASSERT("Unsupported renderer api!");

		return nullptr;
	}
}
