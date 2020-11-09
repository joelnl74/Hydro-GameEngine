#pragma once
#include <stdint.h>

#include "../../Renderer/Texture.h"
#include "OpenGLDebugger/OpenglErrorHandler.h"

namespace Hydro
{
	class OpenGLTexture : public Texture {

	public:
		OpenGLTexture(uint32_t width, uint32_t height);
		OpenGLTexture(const std::string& path);
		~OpenGLTexture();

		virtual void Bind(uint32_t slot = 0) const override;
		virtual void UnBind() const override;
		virtual void SetData(void* data, uint32_t size) override;

		inline uint32_t GetWidth() const override { return m_Width; }
		inline uint32_t GetHeight() const override { return m_Height; }

		virtual bool operator==(const Texture& other) const override
		{
			return m_RendererID == ((OpenGLTexture&)other).m_RendererID;
		}

	private:
		std::string m_Path;
		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
		GLenum m_InternalFormat, m_DataFormat;
	};
}
