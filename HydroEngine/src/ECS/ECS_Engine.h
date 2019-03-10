#pragma once
#include "../Hydro.h"

#include "ComponentManager.h"
#include "SystemManager.h"
#include "EntityManager.h"

//TODO add a bunch of defines Create/Delete Component/Entites Get component/components attach detach update system
class ECS_Engine
{
public:
	ComponentManager *m_ComponentManager;
	SystemManager    *m_SystemManager;
	EntityManager    *m_EntityManager;

	void StartUp();
	void ShutDown();

	inline static ECS_Engine &GetInstance()
	{
		return *m_instance;
	}

private:
	static ECS_Engine *m_instance;
};

