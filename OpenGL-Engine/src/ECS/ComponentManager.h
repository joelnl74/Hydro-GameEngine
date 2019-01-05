#pragma once
#include "Component.h"
#include <vector>

class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	std::vector<Component*> components;

	void UpdateComponents();
private:
};

