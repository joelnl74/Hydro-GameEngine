#include "ResourceManager.h"

void ResourceManager::FreeAllResources()
{
	for (auto resource : mResources)
	{
		delete resource.second;
	}
	mResources.clear();
}
void ResourceManager::AddReource(std::string &filePath, Resource *resource)
{
	if (resource == nullptr)
	{
		LOG_WARNING("Resource is a nullptr please make sure the resource exsist's");
	}
	else
	{
		mResources.emplace(&filePath, resource);
	}
}
bool ResourceManager::RemoveResource(std::string &filepath)
{
	delete mResources.find(&filepath)._Ptr;
	mResources.erase(&filepath);
	LOG_WARNING("File not found or already deleted");
	return false;
}
