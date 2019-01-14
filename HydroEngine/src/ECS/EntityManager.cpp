#include "EntityManager.h"



EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
	//Clean up memory
	for (std::pair<unsigned int, Entity*> entity : _entities)
	{
		delete entity.second;
	}
	_entities.clear();
}
//Get an entity from the map
Entity EntityManager::GetEntity(int id)
{
	return &_entities.find(id);
}
//Create an entity and return it
Entity EntityManager::CreateEntity()
{
	Entity entity;
	return entity;
}
//Check if entity is alive if not destory its components
bool EntityManager::Alive(Entity e)
{
	if (_entities.count(e.entityID) > 0)
		return true;

	return false;
}
