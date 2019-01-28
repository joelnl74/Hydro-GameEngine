#pragma once
#include "ComponentManager.h"
#include "../Hydro.h"
class ECS_Engine
{
public:
	ComponentManager *m_ComponentManager;

	ECS_Engine();
	~ECS_Engine();
};

