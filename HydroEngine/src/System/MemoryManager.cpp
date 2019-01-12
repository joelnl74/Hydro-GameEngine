#include <malloc.h>

#include "Allocator.h"
#include"Memory.h"
#include "MemoryManager.h"
MemoryManager* MemoryManager::m_Instance = 0;

MemoryManager::MemoryManager()
{
}

MemoryManager* MemoryManager::Get()
{
	if (m_Instance == nullptr)
	{
		m_Instance = (MemoryManager*)malloc(sizeof(MemoryManager));
		m_Instance = new(m_Instance) MemoryManager();
	}
	return m_Instance;
}
void MemoryManager::ShutDown()
{
	//clear memory
	hdel m_Instance;
}
std::string MemoryManager::BytesToString(int64_t bytes)
{
	static const float gb = 1024 * 1024 * 1024;
	static const float mb = 1024 * 1024;
	static const float kb = 1024;

	std::string result;
	if (bytes > gb)
	{
		result += float((float)bytes / gb);
		result += " GB";
	}
	else if (bytes > mb)
	{
		result += float((float)bytes / mb);;
		result += " MB";
	}
	else if (bytes > kb)
	{
		result += std::to_string(float((float)bytes / kb));
		result += " KB";
	}
	else
	{
		result += float((float)bytes);
		result += " Bytes";
	}
	return result;
}