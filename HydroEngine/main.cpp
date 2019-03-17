#include "src/Engine.h"
#include "src/Hydro.h"
#include "src/ECS/ECS_Engine.h"
#include "src/ECS/Systems/RenderSystem.h"
#include "src/ECS/Systems/CollisionSystem.h"

#include "src/ECS/Components/Sprite.h"
#include "src/ECS/Components/Collision.h"
#include "src/Graphics/Texture.h"
int main()
{
	//Game engine object
	Engine *engine = new Engine();

	Texture *texture = new Texture("Resources/textures/Tiles.png");
	texture->bind();

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (i == 0 || j == 0 || j == 14 || i == 19)
			{
				Entity &wall = ECS_Engine::GetInstance().m_EntityManager->CreateEntity();

				wall.transform->position.x = -400 + (40 * i);
				wall.transform->position.y = -300 + (40 * j);

				wall.transform->scale.x = 40;
				wall.transform->scale.y = 40;

				Sprite* sprite1 = new Sprite();
				Collision *coll1 = new Collision();

				sprite1->setTextureUV(1, 0);

				ECS_Engine::GetInstance().m_ComponentManager->AddComponent(wall, sprite1);
				ECS_Engine::GetInstance().m_ComponentManager->AddComponent(wall, coll1);
			}
		}
	}


	Entity &player = ECS_Engine::GetInstance().m_EntityManager->CreateEntity();

	player.transform->position.x = 0;
	player.transform->position.y = 0;

	player.transform->scale.x = 32;
	player.transform->scale.y = 32;

	Sprite* sprite2 = new Sprite();
	Collision *coll2 = new Collision();

	sprite2->setTextureUV(1, 1);

	ECS_Engine::GetInstance().m_ComponentManager->AddComponent(player, sprite2);
	ECS_Engine::GetInstance().m_ComponentManager->AddComponent(player, coll2);

	RenderSystem *renderSystem = new RenderSystem();
	CollisionSystem *collisionSystem = new CollisionSystem();

	ECS_Engine::GetInstance().m_SystemManager->AttachSystem(renderSystem);
	ECS_Engine::GetInstance().m_SystemManager->AttachSystem(collisionSystem);

	//Run gameloop
	engine->Run();

	delete engine;

}