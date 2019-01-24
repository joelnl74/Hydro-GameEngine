#include "src/Engine.h"
#include "src/Hydro.h"
int main()
{
	Engine *engine = new Engine();

	Entity *entity = new Entity();
	entity->AddComponent(new Sprite(32,32,0,0));
	engine->Run();

	delete engine;
}