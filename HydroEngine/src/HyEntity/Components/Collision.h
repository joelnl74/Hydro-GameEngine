#pragma once
#include "../Component.h"
#include "../../vendor/glm/common.hpp"

class Collision : public Component {
public:

	//Transform  &transform = ECS_Engine::GetInstance().m_EntityManager->GetEntityByID(entityID).transform;
	bool trigger = false;

	void Start()
	{

	}

	void Update()
	{

	}
};
