#include "src/Engine.h"
#include "src/Hydro.h"

int main()
{
	//Game engine object
	Engine *engine = new Engine();

	//Run gameloop
	engine->Run();

	delete engine;

}