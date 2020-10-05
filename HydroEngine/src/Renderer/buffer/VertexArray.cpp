#include <HydroEngine\src\Core\Assert.h>

#include "VertexArray.h"
#include "../Renderer.h"

#include "../../Platform/OpenGL/OpenGLVertexArray.h"

namespace Hydro
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetRendererAPI().GetAPI())
		{
		case RendererApiType::None: return nullptr;
		case RendererApiType::OpenGL: return new OpenGLVertexArray();
		}

		HY_ASSERT("Unsupported renderer api!");

		return nullptr;
	}
}
