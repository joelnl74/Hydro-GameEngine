#pragma once

namespace Hydro
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual void Bind(unsigned int slot = 0) const = 0; 
		virtual void UnBind() const = 0;

		virtual inline int  GetWidth() const = 0;
		virtual inline int	GetHeight() const = 0;
		virtual inline int	GetBytePerPixel() const = 0;
	};
}