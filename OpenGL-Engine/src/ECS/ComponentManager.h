#pragma once
#include "Component.h"
#include <unordered_map>

//template <typename ComponentType>

class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();
	std::vector<Component*> components;
	void UpdateComponents();
	//EntityID-> is the reference which this component belongs to
	//void CreateComponent(ComponentType, const int EntityID);
private:
	//std::unordered_map<ComponentType, ComponentType> components;
};

