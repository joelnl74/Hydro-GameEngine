#pragma once
#include <unordered_map>
#include "GameObject.h"
#include "Component.h"


namespace Hydro
{
	class World
	{
	public:		
		void StartUp();
		void ShutDown();
		void Update(float deltaTime = 0);

		GameObject& CreateGameObject();
		GameObject* FindGameObject(unsigned int id);

		inline static World &GetInstance()
		{
			return *m_instance;
		}
	private:
		static World *m_instance;
		std::unordered_map<unsigned int, GameObject*> m_GameObjects;
		int nextId = 0;
	};
}

