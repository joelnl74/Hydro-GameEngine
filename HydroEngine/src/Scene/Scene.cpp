#include "scene.h"
#include "Entity.h"

namespace Hydro 
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity entity = { m_Registry.create(), this };

		return entity;
	}

	void Scene::DestroyEntity(Entity entity)
	{
		// m_Registry.destroy(entity);
	}

	void Scene::OnUpdate()
	{
	}
}