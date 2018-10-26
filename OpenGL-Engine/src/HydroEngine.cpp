#include "HydroEngine.h"

static const int WIDTH = 1024;
static const int HEIGHT = 768;

using namespace Engine;

	HydroEngine::HydroEngine()
	{
		//Running2DMode you can go to file load and it will load up a 2d scene
		//Running3DMode you will see a moving cube
		_engineMode = EngineMode::Running2DMode;

		//Logger
		gLogger.StartUp();
		//create objects needed for the engine and there references
		_window = new Window(WIDTH, HEIGHT, "Hydro-Engine");
		gRenderManager.StartUp();
		_camera = new Camera(720, 480, CameraMode::projection);
		_editor = new Editor(_window->getWindow(), _camera);
		_audioEngine = new AudioEngine();

		//TODO: REMOVE DEBUG CODE ENGINEMODE TESTING
		if (_engineMode == EngineMode::Running2DMode)
		{
			gRenderManager.GetInstance().shader->SetMatrix4("orthographicModel", _camera->returnProjection());
			gRenderManager.GetInstance().shader->setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));
			//center camera
			_camera->centerCamera(64, 64);
			gRenderManager.GetInstance().shader->SetMatrix4("orthographicModel", _camera->returnProjection());
		}
		//TODO: REMOVE DEBUG CODE ENGINEMODE TESTING
		if (_engineMode == EngineMode::Running3DMode)
		{
			glm::mat4 view;
			view = glm::translate(view, glm::vec3(0, 0, -5.0f));
			_shader = new Shader("Resources/shaders/Vincent.shader");
			_cube = new Cube(_shader);
			_shader->Bind();
			_shader->SetMatrix4("projectionMatirx", _camera->cameraProjection);
			_shader->SetMatrix4("view", view);
			_shader->UnBind();

			glEnable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);
		}
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

		gLogger.ShutDown();
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

		//3D test TEST
		if(_engineMode == EngineMode::Running3DMode)
		_cube->Draw();

		//Draw UI
		_editor->ui->DrawUI();
		// Swap front and back buffers 
		_window->update();
	};