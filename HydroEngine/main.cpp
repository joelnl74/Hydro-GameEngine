#include "src/Engine.h"
#include "src/Hydro.h"

#include "src/HyEntity/Components/Sprite.h"
#include "src/HyEntity/Components/Collision.h"
#include "src/Graphics/Texture.h"
int main()
{
	//Game engine object
	Engine *engine = new Engine();

	//Texture *texture = new Texture("Resources/textures/Tiles.png");
	//texture->bind();

	////Run gameloop
	engine->Run();

	delete engine;

}