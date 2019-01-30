#include "src/Engine.h"
#include "src/Hydro.h"


#include "src/ECS/ECS_Engine.h"
int main()
{
	Engine *engine = new Engine();
	
	Entity entity = ECS_Engine::GetInstance().m_EntityManager->CreateEntity();
	Entity entity1 = ECS_Engine::GetInstance().m_EntityManager->CreateEntity();

	ECS_Engine::GetInstance().m_ComponentManager->AddComponent(entity, hnew Sprite(32, 32, 0, 0));
	ECS_Engine::GetInstance().m_ComponentManager->AddComponent(entity1, hnew Sprite(32, 32, 32, 0));

	Sprite sprite = ECS_Engine::GetInstance().m_ComponentManager->GetComponent<Sprite>(entity1);
	sprite.setPosition(64, 64);
	std::vector<Component*> sprites = ECS_Engine::GetInstance().m_ComponentManager->GetComponentsOfType<Sprite>();

	engine->Run();



	delete engine;
}