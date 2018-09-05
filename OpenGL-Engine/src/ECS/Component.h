#pragma once
#include "Entity.h"
class Component
{
	virtual void Update() = 0;
public:
private:
	Entity * entity;
};

