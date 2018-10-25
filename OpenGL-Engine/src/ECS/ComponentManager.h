#pragma once
#include "Component.h"
#include <unordered_map>
class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();
	//EntityID-> is the reference which this component belongs to
	void CreateComponent(int EntityID);
private:
};

