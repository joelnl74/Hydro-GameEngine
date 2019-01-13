#pragma once
#include "Entity.h"
#include "../Hydro.h"

//Keeps track of all the entities that are created
class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	//Get a specific entity
	Entity& GetEntity(int id);
	//Create an entity
	Entity* CreateEntity();
private:
	//Collection of all the created entities
};

