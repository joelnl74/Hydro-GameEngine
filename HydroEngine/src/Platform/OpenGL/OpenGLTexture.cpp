#include "OpenGLTexture.h"
#include "OpenGLDebugger/OpenglErrorHandler.h"
#include "../../../vendor/stb_Image/stb_image.h"

namespace Hydro
{
	OpenGLTexture::OpenGLTexture(uint32_t width, uint32_t height) 
		: m_Width(width), m_Height(height)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, GL_RGBA, width, height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	OpenGLTexture::OpenGLTexture(const std::string& path)
		: m_RendererID(0), m_FilePath(path), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
	{
		int width, height, channels;


		m_LocalBuffer = stbi_load(path.c_str(), &width, &height, &channels, 0);

		m_Width = width;
		m_Height = height;
		m_BPP = channels;

		GLCall(glGenTextures(1, &m_RendererID));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));

		if (m_LocalBuffer)
		{
			stbi_image_free(m_LocalBuffer);
		}
	}

	OpenGLTexture::~OpenGLTexture()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, m_RendererID);
	}

	void OpenGLTexture::UnBind() const
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}

	void OpenGLTexture::SetData(void* data, uint32_t size)
	{
		uint32_t bpp = 4;
		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
}


