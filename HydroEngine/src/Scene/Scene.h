#pragma once
#include "../../vendor/entt/include/entt.hpp"

namespace Hydro {

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());
		
		void DestroyEntity(Entity entity);
		void OnUpdate();

	private:
		entt::registry m_Registry;

		friend class Entity;
	};

}