#pragma once
#include <unordered_map>

#include "Entity.h"
#include "../Hydro.h"

#define Destroy_Entity(x)   EntityManager::m_instance->Destroy(x);
#define IsAlive(x)		    EntityManager::m_instance->Alive(x);
#define Get_Entity		    EntityManager::m_instance->GetEntity(x);
#define Create_Entity()     EntityManager::m_instance->CreateEntity();

//Keeps track of all the entities that are created
class EntityManager 
{
public:
	inline static EntityManager &GetInstance()
	{
		return *m_instance;
	}
	//Startup EntityManager
	void StartUp();
	//Shutdown EntityManager
	void ShutDown();
	//Create an entity
	Entity& CreateEntity();
	//return entity
	Entity& GetEntity(Entity e);
	//Check if entity is alive
	bool Alive(Entity e);
	//Destory a entity
	void Destroy(Entity e);
private:
	static EntityManager *m_instance;
	//Collection of all the created entities
	std::unordered_map<unsigned int , Entity*> _entities;
};