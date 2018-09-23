#include "HydroEngine.h"

int WIDTH = 1024;
int HEIGHT = 768;

using namespace Engine;

	HydroEngine::HydroEngine()
	{
		//create objects needed for the engine and there references
		_window = new Window(WIDTH, HEIGHT, "Hydro-Engine");
		RenderManager::Get().StartUp();
		_camera2d = new Camera2D(720, 480);
		_editor = new Editor(_window->getWindow(), _camera2d);
		_audioEngine = new AudioEngine();
	}
	HydroEngine::~HydroEngine()
	{
		RenderManager::Get().ShutDown();

		//clear memory
		delete _audioEngine;
		delete _editor;
		delete _camera2d;
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
		RenderManager::Get().Update();
		//Draw UI
		_editor->ui->DrawUI();
		// Swap front and back buffers 
		_window->update();
	};