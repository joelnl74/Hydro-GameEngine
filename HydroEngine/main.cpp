#include "src/Engine.h"
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
	Engine *engine = hnew Engine();
	FileSystemWindows *fileExplorer = hnew FileSystemWindows();
	
	Texture *texture = new OpenGLTexture("Resources/textures/Tiles.png");
	texture->Bind();

	GameObject &gameobject = World::GetInstance().CreateGameObject();
	gameobject.transform->scale.x = 32;
	gameobject.transform->scale.y = 32;

	gameobject.transform->position.x = 0;
	gameobject.transform->position.y = 0;

	gameobject.AddComponent(hnew PlayerTest());
	gameobject.AddComponent(hnew Sprite());
	gameobject.AddComponent(hnew Collision());

	fileExplorer->ReadAllFilesDirectories("E:\\Dev\\Engine\\Hydro-GameEngine\\HydroEngine\\Resources");

	////Run gameloop
	engine->Run();

	hdel engine;
}