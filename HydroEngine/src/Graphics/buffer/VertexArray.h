#pragma once

namespace Hydro
{
	class VertexArray
	{
	public:
		~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
	};
}


