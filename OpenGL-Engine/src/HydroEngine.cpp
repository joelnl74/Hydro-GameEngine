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
		logger.StartUp();
		logger.GetInstance().Error("Starting Engine");
		//create objects needed for the engine and there references
		_window = new Window(WIDTH, HEIGHT, "Hydro-Engine");
		gRenderManager.StartUp();
		_camera = new Camera(720, 480);
		_editor = new Editor(_window->getWindow(), _camera);
		_audioEngine = new AudioEngine();

		//gRenderManager.GetInstance().shader->SetMatrix4("orthographicModel", _camera->returnProjection());
		//gRenderManager.GetInstance().shader->setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));
		////center camera
		//_camera->centerCamera(64, 64);
		//gRenderManager.GetInstance().shader->SetMatrix4("orthographicModel", _camera->returnProjection());

		//Vincent code
		glm::mat4 view;
		view = glm::translate(view, glm::vec3(0, 0, -5.0f));
		_shader = new Shader("res/shaders/Vincent.shader");
		_cube = new Cube(_shader);
		_shader->Bind();
		_shader->SetMatrix4("projectionMatirx", _camera->cameraProjection);
		_shader->SetMatrix4("view", view);
		_shader->UnBind();

		glEnable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
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

		logger.ShutDown();
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
		//gRenderManager.Update();

		//Vincent
		_cube->Draw();

		//Draw UI
		_editor->ui->DrawUI();
		// Swap front and back buffers 
		_window->update();
	};