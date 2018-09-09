#include "HydroEngine.h"

int WIDTH = 1024;
int HEIGHT = 768;

HydroEngine::HydroEngine()
{
	//create objects needed for the engine and there references
	_window = new Window(WIDTH, HEIGHT, "Hydro-Engine");
	_layerManager = new LayerManager();
	_editorUI = new EditorUI(_window->getWindow(), _layerManager);
	_audioEngine = new AudioEngine();
}
HydroEngine::~HydroEngine()
{
	//clear memory
	delete _editorUI;
	delete _layerManager;
	delete _audioEngine;
	delete _window;
}
void HydroEngine::StartUp()
{
	//startup all diffrent parts of the engine
	
}
void HydroEngine::ShutDown()
{
	//close all diffrent parts of the engine in reverse order of startup
}
