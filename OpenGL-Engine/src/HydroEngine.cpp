#include "HydroEngine.h"

enum  EngineMode
{
	EditorMode,
	Running2DMode,
	Running3DMode
};

int WIDTH = 1024;
int HEIGHT = 768;

using namespace Engine;

	HydroEngine::HydroEngine()
	{
		//create objects needed for the engine and there references
		_window = new Window(WIDTH, HEIGHT, "Hydro-Engine");
		gRenderManager.StartUp();
		_camera = new Camera(720, 480);
		_editor = new Editor(_window->getWindow(), _camera);
		_audioEngine = new AudioEngine();
	}
	HydroEngine::~HydroEngine()
	{
		gRenderManager.ShutDown();

		//clear memory
		delete _audioEngine;
		delete _editor;
		delete _camera;
		delete _window;

		ImGui_ImplGlfwGL3_Shutdown();
		ImGui::DestroyContext();
	}
	void HydroEngine::CheckInput()
	{
		_editor->UpdateInput();
	}
	void HydroEngine::Draw()
	{
		//Clear Screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Draw Graphics
		gRenderManager.Update();
		//Draw UI
		_editor->ui->DrawUI();
		// Swap front and back buffers 
		_window->update();
	};