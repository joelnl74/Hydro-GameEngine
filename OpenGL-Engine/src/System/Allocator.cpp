#include "Allocator.h"
#include "MemoryManager.h"
#include <assert.h>

#define HY_MEMORY_ALIGNMENT 16
#define HY_ALLOC(size)	_aligned_malloc(size, HY_MEMORY_ALIGNMENT)
#define HY_FREE(block)	_aligned_free(block);

void* Allocator::Allocate(size_t size)
{
	assert(size < 1024 * 1024 * 1024);
	MemoryManager::Get()->memoryStats.totalAllocated += size;
	MemoryManager::Get()->memoryStats.currentUsed += size;
	MemoryManager::Get()->memoryStats.totalAllocations++;

	size_t actualSize = size + sizeof(size_t);
	uint16_t* result = (uint16_t*)HY_ALLOC(actualSize);
	memset(result, 0, actualSize);
	memcpy(result, &size, sizeof(size_t));
	result += sizeof(size_t);
	return result;
}
void* Allocator::AllocateDebug(size_t size, const char* file, unsigned int line)
{
	assert(size < 1024 * 1024 * 1024);
	return Allocate(size);
}
void Allocator::Free(void* block)
{
	uint16_t* memory = ((uint16_t*)block) - sizeof(size_t);
	size_t size = *(size_t*)memory;
	MemoryManager::m_Instance->memoryStats.totalFreed += size;
	MemoryManager::m_Instance->memoryStats.currentUsed -= size;
	HY_FREE(memory);
}
void Allocator::FreeDebug(void* block, const char* file, unsigned int line)
{
	Free(block);
}
