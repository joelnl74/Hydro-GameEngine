#pragma once

namespace Hydro
{
	class VertexBuffer
	{
	private:
		unsigned int m_RendererID;
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
	};
}
