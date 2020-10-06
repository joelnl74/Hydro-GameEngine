#pragma once
#include "../../Renderer/RendererAPI.h"
namespace Hydro
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Draw2DIndexed(VertexArray* VertexArray, uint32_t count) override;
		virtual void Draw3D() override;
		virtual void Draw3DIndexed() override;
		virtual void DrawLine() override;
		virtual void Clear() override;
	};
}


