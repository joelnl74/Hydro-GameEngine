#pragma once
#include <string.h>

#include "Hydro.h"
#include "Graphics/Window.h"
#include "Graphics/RenderManager.h"
#include "audio/AudioEngine.h"
#include "Graphics/Camera.h"
#include "ECS/ECS_Engine.h"
#include "RescourceManagement/SceneManager/Scene.h"
//https://github.com/joelnl74/Hydro-GameEngine 

enum  EngineMode
{
	EditorMode,
	Running2DMode,
	Running3DMode
};

namespace HY_Engine
{
	class HydroEngine
	{
	public:
		HydroEngine();
		~HydroEngine();
		void CheckInput();
		void Draw();
	//Simple 2dcamera class
		Camera* _camera;
		Window* _window;
		AudioEngine* _audioEngine;
		Time gTime;
	private:
		EngineMode _engineMode;
		Scene *_scene;

};
}

