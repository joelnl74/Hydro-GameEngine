#pragma once#
#include "../../Graphics/buffer/IndexBuffer.h"

namespace Hydro
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(const unsigned int* data, unsigned int count);
		~OpenGLIndexBuffer();

		void Bind() const override;
		void UnBind() const override;

		inline unsigned int GetCount() const override { return m_Count; }

	private:
		unsigned int m_RendererID;
		unsigned int m_Count;
	};
}
