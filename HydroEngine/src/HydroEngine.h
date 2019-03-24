#pragma once
#include <string.h>

#include "Hydro.h"
#include "Graphics/Window.h"
#include "Graphics/RenderManager.h"
#include "Editor//EditorUI.h"
#include "Audio/AudioManager.h"
#include "Utilities/Platform/WindowsInput.h"
#include "Graphics/Camera.h"
#include "ECS/ECS_Engine.h"
//#include "RescourceManagement/SceneManager/Scene.h"
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
		void Draw();
	//Simple 2dcamera class
		Camera* _camera;
		Window* _window;
		WindowsInput *_input;
		AudioManager *_audio;
		Time gTime;
	private:
		EditorUI *_editUI;
		EngineMode _engineMode;
		//Scene *_scene;

};
}

