#pragma once
#include "../../vendor/glm/glm.hpp"
#include "buffer/VertexArray.h"
#include <memory>

namespace Hydro {

	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, OpenGL = 1
		};
	public:
		virtual void Init() = 0;
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Draw2DIndexed(VertexArray *VertexArray, uint32_t count) = 0;
		virtual void Draw3D() = 0;
		virtual void Draw3DIndexed() = 0;
		virtual void DrawLine() = 0;
		virtual void Clear() = 0;

		inline static API GetAPI() { return s_API; }
		static std::unique_ptr<RendererAPI> Create();

	private:
		static API s_API;
	};
}
