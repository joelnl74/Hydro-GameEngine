#include "HydroEngine.h"
#include "Editor/EditorUI.h"

#include <GLFW/glfw3.h>

//TEST
#include "Core/Events/WindowResizeEvent.h"

namespace Hydro
{
	#define BIND_EVENT_FN(fn) std::bind(&HydroEngine::##fn, this, std::placeholders::_1)


	//Only Start major parts of the engine later on here so change Camera editor Window all to the graphics part of the engine
	HydroEngine::HydroEngine()
	{
		Logger::Init();
		Time::m_Instance->StartUp();
		
		_window = Window::Create();
		_window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		WindowsInput::s_Instance->StartUp((GLFWwindow*)_window->GetNativeWindow());
		World::GetInstance().StartUp();
		Renderer::GetInstance().StartUp();

		_editUI = new EditorUI((GLFWwindow*)_window->GetNativeWindow());

		_audio = new AudioManager();
		_audio->Init();
		_audio->SetListener();

		buffer = _audio->LoadAudioSound("Resources/sounds/Hydro_Engine_Sound1.ogg");

		source = new AudioSource();
		source->Init(0, 0, 0, 1, 1, buffer);

		model = new Model("Resources/fbx/cerberus.fbx");
		shader = Shader::Create("Resources/shaders/Base3D.shader");
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
			Renderer::GetAPI().SetClearColor(glm::vec4(1));
			Renderer::GetAPI().Clear();

			source->playSource(&buffer);

			// Update world.
			// pre Update?
			// World::GetInstance().Update();
			// post Update?;

			model->Draw(*shader);

			// Update renderer.

			//Draw UI
			// editor needs to be its own lib
			// _editUI->DrawUI();
			// Swap front and back buffers 
			
			_window->OnUpdate();
		};
	}

	void HydroEngine::OnEvent(Event &event)
	{
		// Create dispatcher so we dont needto dynamically cast this
		WindowResizeEvent *a = dynamic_cast<WindowResizeEvent*>(&event);
		glViewport(1, 1, a->GetWidth(), a->GetHeight());

		LOG_INFO("{0},{1}", a->GetWidth(), a->GetHeight());
	}
}

