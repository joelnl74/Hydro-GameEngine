#pragma once
#include "../vendor/glm/glm.hpp"

namespace Hydro {

	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, OpenGL = 1, DirectX11 = 2, Vulkan = 3, DirectX12 
		};

	public:
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Draw3D() = 0;
		virtual void Draw3DIndexed() = 0;
		virtual void Draw2DBatched() = 0;
		virtual void DrawLine() = 0;
		virtual void Clear() = 0;

		inline static API GetAPI() { return s_API; }
	private:
		static API s_API;
	};
}