#pragma once
#include <string>
struct MemoryStats
{
	int64_t totalAllocated;
	int64_t totalFreed;
	int64_t currentUsed;
	int64_t totalAllocations;

	MemoryStats()
		: totalAllocated(0), totalFreed(0), currentUsed(0), totalAllocations(0)
	{
	}
};
class MemoryManager
{
public:
	void StartUp();
	void ShutDown();

	MemoryManager();

	inline MemoryStats GetMemoryStats() const { return memoryStats; }

	MemoryStats memoryStats;

	static MemoryManager* Get();
	static MemoryManager *m_Instance;
	static std::string BytesToString(int64_t bytes);
private:

};

