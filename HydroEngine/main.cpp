#include "src/Engine.h"
#include "src/Hydro.h"

#include "src/ECS/Systems/RenderSystem.h"
#include "src/ECS/ECS_Engine.h"
int main()
{
	Engine *engine = new Engine();
	
	RenderSystem *rendersystem = new RenderSystem();

	ECS_Engine::GetInstance().m_SystemManager->AttachSystem(rendersystem);

	
	for (int x = 0; x < 10000; x++)
	{
		Entity entity1 = ECS_Engine::GetInstance().m_EntityManager->CreateEntity();
	
		entity1.transform->scale.x = 32;
		entity1.transform->scale.y = 32;

		entity1.transform->position.x = 0;
		entity1.transform->position.y = 0;

		ECS_Engine::GetInstance().m_ComponentManager->AddComponent(entity1, hnew Sprite(entity1));
	}

	rendersystem->update = true;

	engine->Run();



	delete engine;
}