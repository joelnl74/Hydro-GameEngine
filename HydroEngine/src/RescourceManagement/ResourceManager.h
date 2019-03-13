#pragma once
#include <unordered_map>
#include <string>

#include "../Hydro.h"
#include "Resource.h"
class ResourceManager
{
public:
	void FreeAllResources();
	void AddReource(std::string &filePath, Resource *resource);
	bool RemoveResource(std::string &filePath);
	template <typename T>
	T* getResource(const std::string& name) {
		return dynamic_cast<T*>(mResources.find(name)->second);
	}
private:
	//Resources managed for this scene
	std::unordered_map<std::string*, Resource*> mResources;
};