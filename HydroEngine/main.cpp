#include "src/HydroEngine.h"
#include "src/Hydro.h"

#include "src/HyEntity/Components/Sprite.h"
#include "src/HyEntity/Components/Collision.h"
#include "src/HyEntity/Components/PlayerTest.h"
#include "src/Platform/OpenGL/OpenGLTexture.h"
#include "src/Platform/Windows/FileSystemWindows.h"

// normally dont do this but for now its okay
using namespace Hydro;

int main()
{
	//Game engine object
	HydroEngine *engine = new HydroEngine();
	FileSystem *fileExplorer = new FileSystemWindows();
	
	Texture *texture = new OpenGLTexture("Resources/textures/cerberus_A.png");
	texture->Bind();

	GameObject &gameobject = World::GetInstance().CreateGameObject();
	gameobject.transform->scale.x = 32;
	gameobject.transform->scale.y = 32;

	gameobject.transform->position.x = 0;
	gameobject.transform->position.y = 0;

	gameobject.AddComponent(new PlayerTest());
	gameobject.AddComponent(new Sprite());
	gameobject.AddComponent(new Collision());

	fileExplorer->ReadAllFilesDirectories("E:\\Dev\\Engine\\Hydro-GameEngine\\HydroEngine\\Resources");

	////Run gameloop
	engine->Run();

	delete engine;
}