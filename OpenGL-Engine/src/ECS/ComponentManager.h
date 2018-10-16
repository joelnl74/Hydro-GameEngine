#pragma once
#include "Component.h"
#include <unordered_map>
class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	void AddComponent(int EntityId, Component component);

private:

};

