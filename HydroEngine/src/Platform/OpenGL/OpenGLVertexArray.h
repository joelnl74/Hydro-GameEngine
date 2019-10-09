#pragma once
#include "../../Renderer/buffer/VertexArray.h"
#include"OpenGLVertexBuffer.h"

namespace Hydro
{
	class OpenGLVertexbufferLayout;
	class OpenGLVerterArray : public VertexArray
	{
	public:
		OpenGLVerterArray();
		~OpenGLVerterArray();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		void AddBuffer(const OpenGLVertexBuffer& vb, const OpenGLVertexbufferLayout& layout);
	private:
		unsigned int m_RendererID;
	};
}
