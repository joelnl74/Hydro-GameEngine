#include "HydroEngine.h"

static const int WIDTH = 1024;
static const int HEIGHT = 768;

using namespace Engine;

//Only Start major parts of the engine later on here so change Camera editor Window all to the graphics part of the engine
	HydroEngine::HydroEngine()
	{
		//Running2DMode you can go to file load and it will load up a 2d scene
		//Running3DMode you will see a moving cube
		_engineMode = EngineMode::Running2DMode;

		gLogger.StartUp();
		gTime.StartUp();

		_window = hnew Window(WIDTH, HEIGHT, "Hydro-Engine");
		gRenderManager.StartUp();
		_camera = hnew Camera(800, 600, CameraMode::projection);
		_editor = hnew Editor(_window->getWindow(), _camera);
		//_audioEngine = new AudioEngine();

		//TODO: REMOVE DEBUG CODE ENGINEMODE TESTING
		if (_engineMode == EngineMode::Running2DMode)
		{
			gRenderManager.GetInstance().shader->SetMatrix4("orthographicModel", _camera->returnProjection());
			gRenderManager.GetInstance().shader->setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));
			//center camera
			_camera->centerCamera(0, 0);
			gRenderManager.GetInstance().shader->SetMatrix4("orthographicModel", _camera->returnProjection());
		}
	}
	HydroEngine::~HydroEngine()
	{
		gRenderManager.ShutDown();
		//clear memory
		hdel _editor;
		hdel _camera;

		//hdel _audioEngine;

		ImGui_ImplGlfwGL3_Shutdown();
		ImGui::DestroyContext();

		gTime.ShutDown();
		gLogger.ShutDown();
		hdel _window;
	}
	void HydroEngine::CheckInput()
	{
		_editor->UpdateInput();
	}
	void HydroEngine::Draw()
	{
		//Clear Screen
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);;
		
		//Draw Graphics

		//2D SpriteBatch TEST
		if(_engineMode == EngineMode::Running2DMode)
		gRenderManager.Update();

		//Draw UI
		_editor->ui->DrawUI();
		// Swap front and back buffers 
		_window->update();
	};