#pragma once
#include <unordered_map>

#include "Entity.h"
#include "../Hydro.h"

//Keeps track of all the entities that are created
class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	//Create an entity
	Entity& CreateEntity();
	//return entity
	Entity& GetEntity(Entity e);
	//Check if entity is alive
	bool Alive(Entity e);
	//Destory a entity
	void Destroy(Entity e);
private:
	//Collection of all the created entities
	std::unordered_map<unsigned int , Entity*> _entities;
};

