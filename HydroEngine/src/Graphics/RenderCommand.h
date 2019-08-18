#pragma once
#include "RendererAPI.h"


namespace Hydro
{
	class RenderCommand
	{
		inline static void SetClearColor(const glm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}

		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}

	private:
		static RendererAPI* s_RendererAPI;
	};
}