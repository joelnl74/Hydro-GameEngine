#pragma once
#include <vector>
#include "../../ECS/Entity.h"
/*
Temp fix for diffrent scene to run, can only have one active scene a time
*/
class Scene
{
public:
	Scene();
	~Scene();

	void AddEntity(Entity* entiy);
	void RemoveEntity(Entity* entity);

private:
	//All entities that belong to this scene
	std::vector<Entity*> entities;
};

