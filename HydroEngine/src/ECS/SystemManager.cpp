#include "SystemManager.h"


//TODO m_System.size() not a good value
void SystemManager::AttachSystem(System * system)
{
	m_Systems.emplace(m_Systems.size(), system);
}
//TODO Detach a system from updating
void SystemManager::Detachsystem(System * system)
{
}
//TODO set priority of the system update
void SystemManager::SetSystemPriority(System * system)
{
}
//TODO Pre/Post Update
void SystemManager::UpdateSystems()
{
	for (std::pair<int, System*> system : m_Systems)
	{
		system.second->Update();
	}
}
