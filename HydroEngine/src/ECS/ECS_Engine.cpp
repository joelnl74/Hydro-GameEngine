#include "ECS_Engine.h"
#include "ComponentManager.h"


ECS_Engine::ECS_Engine()
{
	m_ComponentManager = new ComponentManager();
}


ECS_Engine::~ECS_Engine()
{
	delete m_ComponentManager;
}
