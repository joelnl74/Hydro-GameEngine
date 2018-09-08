#pragma once
#include "../Components/Transform.h"
class Entity
{
public:
	Entity();
	~Entity();
	Transform *transform = new Transform();
};

