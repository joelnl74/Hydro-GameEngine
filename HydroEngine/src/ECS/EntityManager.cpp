#include "EntityManager.h"

EntityManager *EntityManager::m_instance = 0;

void EntityManager::StartUp()
{
	//EntityManager
	if (m_instance == 0)
	{
		m_instance = hnew EntityManager();
	}
}

void EntityManager::ShutDown()
{
	//Clean up memory
	for (std::pair<unsigned int, Entity*> entity : _entities)
	{
		delete entity.second;
	}
	_entities.clear();

	//Delete instance
	hdel m_instance;
}

//Create an entity and return it
Entity& EntityManager::CreateEntity()
{
	Entity *entity = new Entity();
	entity->entityID = _entities.size() + 1;
	//TODO KEEP TRACK OF EMPTY ID's and reuse them
	_entities.emplace(_entities.size() + 1, entity);

	return *entity;
}

//Return entity by id
Entity& EntityManager::GetEntity(Entity e)
{
	return *_entities.at(e.entityID);
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
void EntityManager::Destroy(Entity e)
{
	delete _entities.at(e.entityID);
	_entities.erase(_entities.find(e.entityID));
}
