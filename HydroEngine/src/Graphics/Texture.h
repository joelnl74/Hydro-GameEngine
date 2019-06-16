#pragma once

#include <string.h>
#include <iostream>
#include "Shader.h"

namespace Hydro
{
	class Texture
	{
	private:
		unsigned int m_rendererID;
		std::string m_FilePath;
		unsigned char* m_LocalBuffer;

		int id;
		int m_Width;
		int m_Height;
		int m_BPP;

		float offsetX;
		float offsetY;
	public:
		Texture(const std::string& path);
		~Texture();

		void bind(unsigned int slot = 0) const;
		void unBind() const;

		inline int  getWidth() const { return m_Width; }
		inline int	getHeight() const { return m_Height; }
		inline int	getBytePerPixel() const { return m_BPP; }
	};
}