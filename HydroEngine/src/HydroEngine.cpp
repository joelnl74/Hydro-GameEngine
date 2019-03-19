#include "HydroEngine.h"
#include "Editor/EditorUI.h"
static const int WIDTH = 1024;
static const int HEIGHT = 768;

using namespace HY_Engine;

//Only Start major parts of the engine later on here so change Camera editor Window all to the graphics part of the engine
	HydroEngine::HydroEngine()
	{
		Logger::m_Instance->StartUp();
		gTime.StartUp();
		_window = hnew Window(WIDTH, HEIGHT, "Hydro-Engine");
		WindowsInput::GetInstance().StartUp(_window->getWindow());
		ECS_Engine::GetInstance().StartUp();
		RenderManager::GetInstance().StartUp();

		//_audioEngine = hnew AudioEngine();
	}
	HydroEngine::~HydroEngine()
	{
		RenderManager::GetInstance().ShutDown();
		ECS_Engine::GetInstance().ShutDown();
		//clear memory
		//hdel _audioEngine;
		hdel _camera;

		ImGui_ImplGlfwGL3_Shutdown();
		ImGui::DestroyContext();

		gTime.ShutDown();
		Logger::m_Instance->ShutDown();
		WindowsInput::GetInstance().ShutDown();
		hdel _window;

	}
	void HydroEngine::Draw()
	{
		//Clear Screen
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);;

		//update systems
		ECS_Engine::GetInstance().m_SystemManager->UpdateSystems();

		//Draw UI
		// Swap front and back buffers 
		_window->update();
	};