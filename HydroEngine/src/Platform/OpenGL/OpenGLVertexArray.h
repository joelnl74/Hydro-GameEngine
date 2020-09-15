#pragma once
#include "../../Renderer/buffer/VertexArray.h"
#include "../../Renderer/buffer/VertexBuffer.h"

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

		void AddBuffer(const VertexBuffer* vb, const BufferLayout* layout);
	private:
		unsigned int m_RendererID;
	};
}
