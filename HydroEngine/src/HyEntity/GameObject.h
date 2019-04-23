#pragma once
#include <vector>

#include "Transform.h"

class Component;
class GameObject
{
public:
	GameObject();
	~GameObject();

	void AddComponent(Component *component)
	{
		components.push_back(component);
	}

	Transform *transform;
private:
	std::vector<Component*> components;
};

