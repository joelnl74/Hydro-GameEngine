#pragma once
#include "Renderer/Window.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"

#include <string.h>

#include "Hydro.h"
// #include "Audio/AudioManager.h"
#include "Platform/Windows/WindowsInput.h"

enum  EngineMode
{
	EditorMode,
	Running2DMode,
	Running3DMode
};

namespace Hydro
{
	class HydroEngine
	{
	public:
		HydroEngine();
		~HydroEngine();

		void Run();
		//void OnEvent(Event& event);

	//Simple 2dcamera class
		Camera* _camera;
		Window* _window;
		// AudioManager *_audio;
	private:
		EngineMode _engineMode;

		//test
		// AudioSource *source;
		Shader *shader;
		Model* model;
		int buffer;
	};
}

