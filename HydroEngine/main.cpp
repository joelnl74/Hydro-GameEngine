#include "src/Engine.h"
#include "src/Hydro.h"
int main()
{
	Engine *engine = new Engine();

	//Create entity, should be done by entity manager
	Entity *entity = new Entity();
	//Add components to entity
	entity->AddComponent(new Sprite(32,32,0,0));
	//Get first certain component
	Sprite *sprite = entity->GetComponent<Sprite>();

	engine->Run();

	delete engine;
}