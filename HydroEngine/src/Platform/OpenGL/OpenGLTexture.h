#pragma once
#include "../../Renderer/Texture.h"
#include <string>

namespace Hydro
{
	class OpenGLTexture : public Texture {

	public:
		OpenGLTexture(const std::string& path);
		~OpenGLTexture();

		virtual void Bind(unsigned int slot = 0) const override;
		virtual void UnBind() const override;

		inline int  GetWidth() const override { return m_Width; }
		inline int	GetHeight() const override { return m_Height; }
		inline int	GetBytePerPixel() const override { return m_BPP; }

	private:
		unsigned int m_rendererID;

		int id;
		int m_Width;
		int m_Height;
		int m_BPP;

		float offsetX;
		float offsetY;

		std::string m_FilePath;
		unsigned char* m_LocalBuffer;
	};
}
