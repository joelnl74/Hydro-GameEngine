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
//Create an entity and return it
Entity& EntityManager::CreateEntity()
{
	Entity *entity = new Entity();
	//TODO KEEP TRACK OF EMPTY ID's and reuse them
	_entities.emplace(_entities.size() + 1, entity);

	return *entity;
}
//Check if entity is alive if not destory its components
bool EntityManager::Alive(Entity e)
{
	if (_entities.count(e.entityID) > 0)
		return true;

	return false;
}
//TODO make this more safe
//Destory an entity and remove it from the heap!
void EntityManager::Destroy(int id)
{
	delete _entities.at(id);
	_entities.erase(_entities.find(id));
}
