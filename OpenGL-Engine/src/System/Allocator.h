#pragma once
class Allocator
{
public:
	static void* Allocate(size_t size);
	static void* AllocateDebug(size_t size, const char* file, unsigned int line);

	static void Free(void* block);
	static void FreeDebug(void* block, const char* file, unsigned int line);
};

