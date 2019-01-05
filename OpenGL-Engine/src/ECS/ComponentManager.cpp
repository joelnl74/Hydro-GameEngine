#include "ComponentManager.h"



ComponentManager::ComponentManager()
{
}


ComponentManager::~ComponentManager()
{
}
void ComponentManager::UpdateComponents()
{
	for (Component * component : components)
	{
		component->Update();
	}
}
