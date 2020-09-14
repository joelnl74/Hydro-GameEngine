#include "VertexArray.h"
#include "../../Platform/OpenGL/OpenGLVertexArray.h"
#include "../Renderer.h"
namespace Hydro
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetRendererAPI().GetAPI())
		{
		case RendererApiType::None:    return nullptr;
		case RendererApiType::OpenGL:  return new OpenGLVerterArray();
		}

		return nullptr;
	}
}