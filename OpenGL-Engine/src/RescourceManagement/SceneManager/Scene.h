#pragma once
#include <vector>

#include "../../ECS/Entity.h"
#include "../../Graphics/Camera.h"
class Scene
{
public:
	Scene();
	~Scene();
	std::vector<Entity> gameObjects;
private:
	//MainCamera, accesible from anywhere probally somesort of static variable which can be used by any class
	//Camera * mainCamera = new Camera(720, 480);
};

