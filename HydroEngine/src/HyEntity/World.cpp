#include "World.h"
#include "../Hydro.h"

namespace Hydro
{
	World *World::m_instance = 0;

	void World::StartUp()
	{
		if (m_instance == nullptr)
		{
			m_instance = new World();
		}
	}

	void World::ShutDown()
	{
		for (auto x : m_GameObjects)
		{
			hdel x.second;
		}

		m_GameObjects.clear();
	}
	void World::Update(float deltaTime)
	{
		for (int i = 0; i < m_GameObjects.size(); i++)
		{
			m_GameObjects[i]->Update();
		}
	}
	GameObject & World::CreateGameObject()
	{
		GameObject *gameObject = hnew GameObject();
		m_GameObjects.emplace(nextId, gameObject);

		nextId++;

		return *gameObject;
	}
	GameObject* World::FindGameObject(unsigned int id)
	{
		//TODO check if value exsist
		if (m_GameObjects.count(id) == 1)
		{
			return m_GameObjects.at(id);
		}

		return nullptr;
	}
}

