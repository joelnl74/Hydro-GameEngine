#pragma once
#include <string>

#include "../Hydro.h"
class Resource
{
public:
	Resource() { }
	virtual ~Resource()= 0;

	virtual void loadResource() = 0;
	virtual void unloadResource() = 0;

	void setResourceId(unsigned id) { mResourceId = id; };
	unsigned getResourceId() const { return mResourceId; };

	void setResourcePath(const std::string& path) { }
	std::string getResourcePath() const { return mResourcePath; };

protected:
	unsigned mResourceId;
	std::string mResourcePath;
};

