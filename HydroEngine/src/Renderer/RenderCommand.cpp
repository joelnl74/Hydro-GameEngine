#include "RenderCommand.h"

namespace Hydro 
{
	std::unique_ptr<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}