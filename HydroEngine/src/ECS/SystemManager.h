#pragma once
#include <unordered_map>

#include "System.h"
class SystemManager
{
public:
	SystemManager();
	~SystemManager();

	void AttachSystem(System *system);
	
	void Detachsystem(System *system);

	void SetSystemPriority(System *system);

	void UpdateSystems();


private:
	std::unordered_map<int, System*> m_Systems;
};

