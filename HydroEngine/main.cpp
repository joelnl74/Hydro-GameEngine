#include "src/Engine.h"
#include "src/Hydro.h"

#include "src/HyEntity/Components/Sprite.h"
#include "src/HyEntity/Components/Collision.h"
#include "src/Graphics/Texture.h"

// normally dont do this but for now its okay
using namespace Hydro;

int main()
{
	//Game engine object
	Engine *engine = hnew Engine();
	
	Texture *texture = new Texture("Resources/textures/Tiles.png");
	texture->bind();

	GameObject &gameobject = World::GetInstance().CreateGameObject();
	gameobject.transform->scale.x = 32;
	gameobject.transform->scale.y = 32;

	gameobject.transform->position.x = 300;
	gameobject.transform->position.y = 400;

	gameobject.AddComponent(hnew Sprite());
	gameobject.AddComponent(hnew Collision());

	GameObject &gameobject2 = World::GetInstance().CreateGameObject();
	gameobject2.transform->scale.x = 32;
	gameobject2.transform->scale.y = 32;

	gameobject2.AddComponent(hnew Sprite());
	gameobject2.AddComponent(hnew Collision());

	////Run gameloop
	engine->Run();

	hdel engine;
}