#include "src/Engine.h"
#include "src/Hydro.h"

#include "src/ECS/Systems/RenderSystem.h"
#include "src/ECS/ECS_Engine.h"
int main()
{
	Engine *engine = new Engine();
	
	Entity entity = ECS_Engine::GetInstance().m_EntityManager->CreateEntity();
	Entity entity1 = ECS_Engine::GetInstance().m_EntityManager->CreateEntity();

	entity.transform->scale.x = 32;
	entity.transform->scale.y = 32;
	
	entity1.transform->scale.x = 32;
	entity1.transform->scale.y = 32;

	entity1.transform->position.x = 32;
	entity1.transform->position.y = 32;

	RenderSystem *rendersystem = new RenderSystem();
	ECS_Engine::GetInstance().m_SystemManager->AttachSystem(rendersystem);

	ECS_Engine::GetInstance().m_ComponentManager->AddComponent(entity, hnew Sprite(entity));
	ECS_Engine::GetInstance().m_ComponentManager->AddComponent(entity1, hnew Sprite(entity1));

	engine->Run();



	delete engine;
}