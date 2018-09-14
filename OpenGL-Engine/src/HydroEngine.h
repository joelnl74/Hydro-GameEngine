#pragma once
#include <string.h>

#include "Graphics/Window.h"
#include "Graphics/GraphicsEngine.h"
#include "Editor/Editor.h"
#include "audio/AudioEngine.h"
#include "Graphics/Camera2D.h"
//https://github.com/joelnl74/Hydro-GameEngine 
class HydroEngine
{
public:
	HydroEngine();
	~HydroEngine();
	void CheckInput();
	void Draw();
	//split this up more in a renderer, audio, ai, physics engine and so on
	//Simple 2dcamera class
	Camera2D* _camera2d;
	Window* _window;
	GraphicsEngine *_graphicsEngine;
	Editor* _editor;
	AudioEngine* _audioEngine;
};

