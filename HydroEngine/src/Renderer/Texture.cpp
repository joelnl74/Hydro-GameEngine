#include "Texture.h"
#include "Renderer.h"
#include "../Platform/OpenGL/OpenGLTexture.h"

namespace Hydro {

	Texture* Texture::Create(uint32_t width, uint32_t height)
	{
		Texture* result = nullptr;

		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    HY_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  result = new OpenGLTexture(width, height);
		}
		
		return result;
	}

	Texture* Texture::Create(const std::string& filePath)
	{
		Texture* result = nullptr;

		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    HY_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  result = new OpenGLTexture(filePath);
		}

		return result;
	}

}