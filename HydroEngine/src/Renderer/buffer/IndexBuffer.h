#pragma once

namespace Hydro
{
	class IndexBuffer
	{
	public:
		~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual inline unsigned int GetCount() const = 0;

		static IndexBuffer* Create(unsigned int* data, unsigned int count);
	};
}
