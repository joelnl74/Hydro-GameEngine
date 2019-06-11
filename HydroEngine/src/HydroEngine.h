#pragma once
#include <string.h>

#include "Hydro.h"
#include "Graphics/Window.h"
#include "Graphics/RenderManager.h"
#include "Editor//EditorUI.h"
#include "Audio/AudioManager.h"
#include "Utilities/Platform/WindowsInput.h"
#include "Graphics/Camera.h"

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
		void MainLoop();
	//Simple 2dcamera class
		Camera* _camera;
		Window* _window;
		AudioManager *_audio;
	private:
		EditorUI *_editUI;
		EngineMode _engineMode;

		//test
		AudioSource *source;
		int buffer;

};
}

