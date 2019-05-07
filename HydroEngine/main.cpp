#include "src/Engine.h"
#include "src/Hydro.h"

#include "src/HyEntity/GameObject.h"
#include "src/HyEntity/Components/Sprite.h"
#include "src/HyEntity/Components/Collision.h"
#include "src/Graphics/Texture.h"
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

	Sprite *sprite = gameobject->GetComponent<Sprite>();

	////Run gameloop
	engine->Run();

	delete engine;

}