#pragma once
#include <vector>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferLayout.h"

namespace Hydro
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void AddVertexBuffer(VertexBuffer* vertexBuffer) = 0;
		virtual void SetIndexBuffer(IndexBuffer* indexBuffer) = 0;

		virtual const std::vector<VertexBuffer*>& GetVertexBuffers() const = 0;
		virtual const IndexBuffer* GetIndexBuffer() const = 0;

		static VertexArray* Create();
	};
}
