#pragma once
#include <string.h>

#include "Graphics/Window.h"
#include "Graphics/layering/LayerManager.h"
#include "Editor/EditorUI.h"
#include "audio/AudioEngine.h"
//https://github.com/joelnl74/Hydro-GameEngine 
class HydroEngine
{
public:
	HydroEngine();
	~HydroEngine();

	void StartUp();
	void ShutDown();
	//tempFIX
	LayerManager &getLayerManager() { return *_layerManager; }
	//split this up more in a renderer, audio, ai, physics engine and so on
	Window* _window;
	LayerManager* _layerManager;
	EditorUI* _editorUI;
	AudioEngine* _audioEngine;
};

