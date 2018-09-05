#pragma once
#include <vector>

#include "../../Component system/GameObject.h"
#include "../../Graphics/Camera2D.h"
class Scene
{
public:
	Scene();
	~Scene();
	std::vector<GameObject> gameObjects;
private:
	//MainCamera, accesible from anywhere probally somesort of static variable which can be used by any class
	Camera2D * mainCamera = new Camera2D(720, 480);
};

