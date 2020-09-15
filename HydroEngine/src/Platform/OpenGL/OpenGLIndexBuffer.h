#pragma once#
#include "../../Renderer/buffer/IndexBuffer.h"

namespace Hydro
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int* data, unsigned int count);
		~OpenGLIndexBuffer();

		void Bind() const override;
		void UnBind() const override;

		inline unsigned int GetCount() const override { return m_Count; }

	private:
		unsigned int m_RendererID;
		unsigned int m_Count;
	};
}
