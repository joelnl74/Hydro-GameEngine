#pragma once
#include "../../Renderer/buffer/VertexBuffer.h"
namespace Hydro
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(const void* data, unsigned int size);
		~OpenGLVertexBuffer();
		
		virtual void Bind() const override;
		virtual void UnBind() const override;

	private:
		unsigned int m_RendererID;
	};
}