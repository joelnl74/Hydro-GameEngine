#pragma once
#include <string.h>
#include "Renderer/Camera.h"
#include "Hydro.h"
#include "Renderer/Window.h"
#include "Editor//EditorUI.h"
#include "Audio/AudioManager.h"
#include "Platform/Windows/WindowsInput.h"
#include "HyEntity/World.h"
#include "Renderer/Model.h"

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
	//Simple 2dcamera class
		Camera* _camera;
		Window* _window;
		AudioManager *_audio;
	private:
		EditorUI *_editUI;
		EngineMode _engineMode;

		//test
		AudioSource *source;
		OpenGLShader *shader;
		Model* model;
		int buffer;

};
}

