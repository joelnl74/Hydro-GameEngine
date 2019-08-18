#pragma once
#include "../../Graphics/RendererAPI.h"
namespace Hydro
{
	class OpenGLRendererAPI : RendererAPI
	{
	public:
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;
	};
}


