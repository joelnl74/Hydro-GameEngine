#pragma once
#include "VertexBuffer.h"
#include "BufferLayout.h"

namespace Hydro
{
	class VertexArray
	{
	public:
		~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static VertexArray* VertexArray::Create(const VertexBuffer* vb, const BufferLayout* layout);
	};
}


