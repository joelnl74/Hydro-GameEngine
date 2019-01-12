#include "Scene.h"

Scene::Scene()
{
}


Scene::~Scene()
{
}
void Scene::AddEntity(Entity *Entity)
{
	entities.push_back(Entity);
}
void Scene::RemoveEntity(Entity *Entity)
{

}
void Scene::OnSceneLoad()
{

}
void Scene::OnSceneExit()
{

}