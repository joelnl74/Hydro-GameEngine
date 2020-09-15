#include "OpenGLTexture.h"
#include "OpenGLDebugger/OpenglErrorHandler.h"
#include "../../../vendor/stbImage/stb_image.h"

namespace Hydro
{
	OpenGLTexture::OpenGLTexture(const std::string& path)
		: m_rendererID(0), m_FilePath(path), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
	{
		//stbi_set_flip_vertically_on_load(1);

		m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

		GLCall(glGenTextures(1, &m_rendererID));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));

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
		glDeleteTextures(1, &m_rendererID);
	}

	void OpenGLTexture::Bind(unsigned int slot) const
	{
		GLCall(glActiveTexture(GL_TEXTURE0 + slot));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_rendererID));
	}

	void OpenGLTexture::UnBind() const
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}
}


