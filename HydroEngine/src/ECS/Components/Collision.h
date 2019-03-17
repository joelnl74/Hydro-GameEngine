#pragma once
#include "../Component.h"
#include "../../vendor/glm/common.hpp"
#include "../ECS_Engine.h"

class Collision : public Component {
public:

	//Transform  &transform = ECS_Engine::GetInstance().m_EntityManager->GetEntityByID(entityID).transform;
	bool trigger = false;

	inline const glm::vec2 getPosition() const { return ECS_Engine::GetInstance().m_EntityManager->GetEntityByID(entity_ID).transform->position; }
	inline const glm::vec2 getScale()	 const { return ECS_Engine::GetInstance().m_EntityManager->GetEntityByID(entity_ID).transform->scale; }
};
