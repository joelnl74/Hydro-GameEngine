#include "World.h"



World::World()
{
	rendersystem = new RenderSystem();
	ECS_Engine::GetInstance().m_SystemManager->AttachSystem(rendersystem);


	for (int x = 0; x < 20000; x++)
	{
		Entity entity1 = ECS_Engine::GetInstance().m_EntityManager->CreateEntity();

		entity1.transform->scale.x = 32;
		entity1.transform->scale.y = 32;

		entity1.transform->position.x = 0;
		entity1.transform->position.y = 0;

		ECS_Engine::GetInstance().m_ComponentManager->AddComponent(entity1, hnew Sprite(entity1));
	}
}

World::~World()
{
}
