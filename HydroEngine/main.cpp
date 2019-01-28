#include "src/Engine.h"
#include "src/Hydro.h"

#include "src/ECS/ECS_Engine.h"
#include "src/ECS/EntityManager.h"
#include "src/ECS/Components/Sprite.h"
int main()
{
	Engine *engine = new Engine();

	EntityManager::GetInstance().StartUp();
	ECS_Engine *ECS = new ECS_Engine();

	Entity entity = EntityManager::GetInstance().CreateEntity();
	Entity entity1 = EntityManager::GetInstance().CreateEntity();

 	ECS->m_ComponentManager->AddComponent<Sprite>(entity, new Sprite(0,0,0,0));
	ECS->m_ComponentManager->AddComponent<Sprite>(entity1, new Sprite(0, 0, 0, 0));

	engine->Run();

	delete engine;
}