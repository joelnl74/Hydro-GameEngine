#include "HydroEngine.h"
#include "Editor/EditorUI.h"
static const int WIDTH = 1024;
static const int HEIGHT = 768;

using namespace HY_Engine;

//Only Start major parts of the engine later on here so change Camera editor Window all to the graphics part of the engine
	HydroEngine::HydroEngine()
	{
		//Running2DMode you can go to file load and it will load up a 2d scene
		//Running3DMode you will see a moving cube
		_engineMode = EngineMode::Running2DMode;

		Logger::m_Instance->StartUp();
		gTime.StartUp();

		_window = hnew Window(WIDTH, HEIGHT, "Hydro-Engine");
		ECS_Engine::GetInstance().StartUp();
		RenderManager::GetInstance().StartUp();
		_camera = hnew Camera(800, 600, CameraMode::projection);
		_audioEngine = hnew AudioEngine();

		//TODO: REMOVE DEBUG CODE ENGINEMODE TESTING
		if (_engineMode == EngineMode::Running2DMode)
		{
			RenderManager::GetInstance().shader->SetMatrix4("orthographicModel", _camera->returnProjection());
			RenderManager::GetInstance().shader->setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));
			//center camera
			_camera->centerCamera(0, 0);
			RenderManager::GetInstance().shader->SetMatrix4("orthographicModel", _camera->returnProjection());
		}
	}
	HydroEngine::~HydroEngine()
	{
		RenderManager::GetInstance().ShutDown();
		ECS_Engine::GetInstance().ShutDown();
		//clear memory
		hdel _audioEngine;
		hdel _camera;

		ImGui_ImplGlfwGL3_Shutdown();
		ImGui::DestroyContext();

		gTime.ShutDown();
		Logger::m_Instance->ShutDown();
		hdel _window;

	}
	void HydroEngine::CheckInput()
	{
	}
	void HydroEngine::Draw()
	{
		//Clear Screen
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);;
		
		//Draw Graphics

		//2D SpriteBatch TEST
		ECS_Engine::GetInstance().m_SystemManager->UpdateSystems();

		//Draw UI
		// Swap front and back buffers 
		_window->update();
	};