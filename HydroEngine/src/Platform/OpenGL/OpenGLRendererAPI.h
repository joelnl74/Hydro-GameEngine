#pragma once
#include "../../Renderer/RendererAPI.h"
namespace Hydro
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Draw3D() override;
		virtual void Draw3DIndexed() override;
		virtual void Draw2DBatched() override;
		virtual void DrawLine() override;
		virtual void Clear() override;
	};
}


