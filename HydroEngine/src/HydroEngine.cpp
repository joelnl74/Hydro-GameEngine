#include "HydroEngine.h"
#include "Editor/EditorUI.h"

#include <GLFW/glfw3.h>

static const int WIDTH = 800;
static const int HEIGHT = 600;

namespace Hydro
{
	//Only Start major parts of the engine later on here so change Camera editor Window all to the graphics part of the engine
	HydroEngine::HydroEngine()
	{
		Logger::Init();
		Time::m_Instance->StartUp();
		_window = Window::Create();
		WindowsInput::s_Instance->StartUp((GLFWwindow*)_window->GetNativeWindow());
		World::GetInstance().StartUp();
		_editUI = new EditorUI((GLFWwindow*)_window->GetNativeWindow());

		_audio = new AudioManager();
		_audio->Init();
		_audio->SetListener();

		buffer = _audio->LoadAudioSound("Resources/sounds/Hydro_Engine_Sound1.ogg");

		source = new AudioSource();
		source->Init(0, 0, 0, 1, 1, buffer);

		model = new Model("Resource/fbx/box.obj");
		shader = Shader::Create("Resources/shaders/Test.shader");
	}
	HydroEngine::~HydroEngine()
	{
		World::GetInstance().ShutDown();
		//clear memory
		_audio->CleanUp();
		delete _audio;
		delete _camera;

		Time::m_Instance->ShutDown();
		delete _window;
	}
	void HydroEngine::Run()
	{
		while (true)
		{
			//Clear Screen
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);;

			source->playSource(&buffer);

			// Update world.
			// pre Update?
			// World::GetInstance().Update();
			// post Update?;

			model->Draw(*shader);

			int a = 5;
			Logger::GetCoreLogger()->trace(a);

			// Update renderer.
			// RenderManager::GetInstance().m_spriteBatch->Begin();
			// RenderManager::GetInstance().m_spriteBatch->End();
			// RenderManager::GetInstance().m_spriteBatch->Flush();

			//Draw UI
			// editor needs to be its own lib
			// _editUI->DrawUI();
			// Swap front and back buffers 
			
			_window->OnUpdate();
		};
	}
}

