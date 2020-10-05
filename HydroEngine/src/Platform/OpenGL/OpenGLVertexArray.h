#pragma once
#include "../../Renderer/buffer/VertexArray.h"
#include "../../Renderer/buffer/VertexBuffer.h"
#include "../../Renderer/buffer/IndexBuffer.h"

namespace Hydro
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void AddVertexBuffer(VertexBuffer* vertexBuffer) override;
		virtual void SetIndexBuffer(IndexBuffer* indexBuffer) override;

		virtual const std::vector<VertexBuffer*>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const IndexBuffer* GetIndexBuffer() const { return m_IndexBuffer; }
	private:
		uint32_t m_RendererID;
		uint32_t m_VertexBufferIndex = 0;
		std::vector<VertexBuffer*> m_VertexBuffers;
		IndexBuffer* m_IndexBuffer;
	};
}
