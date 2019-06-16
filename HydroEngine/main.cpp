#include "src/Engine.h"
#include "src/Hydro.h"

#include "src/HyEntity/GameObject.h"
#include "src/HyEntity/Components/Sprite.h"
#include "src/HyEntity/Components/Collision.h"
#include "src/Graphics/Texture.h"

// normally dont do this but for now its okay
using namespace Hydro;

int main()
{
	//Game engine object
	Engine *engine = new Engine();

	Texture *texture = new Texture("Resources/textures/Tiles.png");
	texture->bind();


	GameObject *gameobject = new GameObject();
	gameobject->transform->scale.x = 32;
	gameobject->transform->scale.y = 32;

	gameobject->AddComponent(new Sprite());

	gameobject->AddComponent(new Collision());

	bool x = gameobject->HasComponent<Collision>();

	////Run gameloop
	engine->Run();

	delete engine;

}