#pragma once
#include <new>
#include <string>

#include "Allocator.h"

#define hnew new(__FILE__, __LINE__)
#define hdel delete

#pragma warning(disable : 4595)

	inline void* operator new(size_t size)
	{
		return Allocator::Allocate(size);
	}

	inline void* operator new(size_t size, const char* file, uint16_t line)
	{
		return Allocator::AllocateDebug(size, file, line);
	}

	inline void* operator new[](size_t size)
	{
		return Allocator::Allocate(size);
	}

		inline void* operator new[](size_t size, const char* file, uint16_t line)
	{
		return Allocator::AllocateDebug(size, file, line);
	}

		inline void operator delete(void* block)
	{
		Allocator::Free(block);
	}

	inline void operator delete(void* block, const char* file, uint16_t line)
	{
		Allocator::FreeDebug(block, file, line);
	}

	inline void operator delete[](void* block)
	{
		Allocator::Free(block);
	}

		inline void operator delete[](void* block, const char* file, uint16_t line)
	{
		Allocator::FreeDebug(block, file, line);
	}
#pragma warning(default : 4595)

