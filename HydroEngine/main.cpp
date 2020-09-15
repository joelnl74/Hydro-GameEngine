#include "src/HydroEngine.h"
#include "src/Hydro.h"

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

	fileExplorer->ReadAllFilesDirectories("E:\\Dev\\Engine\\Hydro-GameEngine\\HydroEngine\\Resources");

	////Run gameloop
	engine->Run();

	delete engine;
}