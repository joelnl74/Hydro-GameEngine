#pragma once
#include <string.h>

#include "Graphics/Window.h"
#include "Utilities/Logger.h"
#include "Editor/Editor.h"
#include "audio/AudioEngine.h"
#include "Graphics/Camera.h"
#include "../Cube.h"
//https://github.com/joelnl74/Hydro-GameEngine 

namespace Engine
{
	class HydroEngine
	{
	public:
		HydroEngine();
		~HydroEngine();
		void CheckInput();
		void Draw();
	//split this up more in a renderer, audio, ai, physics engine and so on
	//Simple 2dcamera class
		Camera* _camera;
		Window* _window;
		Editor* _editor;
		AudioEngine* _audioEngine;
		RenderManager gRenderManager;
		Logger logger;
	private:
		//Vincent stuf
		Shader *_shader;
		Cube * _cube;
};
}

