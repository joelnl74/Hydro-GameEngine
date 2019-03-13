#include "ECS_Engine.h"
#include "ComponentManager.h"

ECS_Engine *ECS_Engine::m_instance = 0;

//StartUp the ECS Engine
void ECS_Engine::StartUp()
{
	if (m_instance == nullptr)
	{
		m_instance = hnew ECS_Engine();
		m_instance->m_SystemManager = hnew SystemManager();
		m_instance->m_EntityManager = hnew EntityManager();
		m_instance->m_ComponentManager = hnew ComponentManager();
	}
}
//ShutDown the ECS Engine
void ECS_Engine::ShutDown()
{
	hdel m_instance->m_ComponentManager;
	hdel m_instance->m_EntityManager;
	hdel m_instance->m_SystemManager;

	hdel m_instance;
}