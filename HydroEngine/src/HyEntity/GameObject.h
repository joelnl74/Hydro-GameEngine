#pragma once
#include <vector>

#include "Component.h"
#include "Transform.h"
class GameObject
{
public:
	GameObject();
	~GameObject();

	Transform *transform;
private:
	std::vector<Component> components;
};

