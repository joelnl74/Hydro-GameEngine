#pragma once
#include <stdint.h>
#include <string>

namespace Hydro
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual void Bind(uint32_t slot = 0) const = 0;
		virtual void UnBind() const = 0;

		virtual inline uint32_t GetWidth() const = 0;
		virtual inline uint32_t GetHeight() const = 0;

		virtual void SetData(void* data, uint32_t size) = 0;

		virtual bool operator==(const Texture& other) const = 0;
	
	public:
		static Texture* Create(uint32_t width, uint32_t height);
		static Texture* Create(const std::string& filePath);
	};
}
