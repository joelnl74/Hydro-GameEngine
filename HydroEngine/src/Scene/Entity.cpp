#include "Entity.h"

namespace Hydro
{
	Entity::Entity(entt::entity handle, Scene* scene) : 
		m_EntityHandle(handle), m_scene(scene)
	{
	}
}

