#include "src/Engine.h"
#include "src/Hydro.h"
#include "src/ECS/World.h"

int main()
{
	//Game engine object
	Engine *engine = new Engine();
	
	//Game world we are currently using can also be seen as a scene
	World  *world = new World();

	//Run gameloop
	engine->Run();

	//Clean up engine
	delete world;
	delete engine;

}