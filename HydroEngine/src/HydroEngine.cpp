#include "HydroEngine.h"

#include <GLFW/glfw3.h>

namespace Hydro
{
	//Only Start major parts of the engine later on here so change Camera editor Window all to the graphics part of the engine
	HydroEngine::HydroEngine()
	{
		Logger::Init();
		Time::m_Instance->StartUp();
		
		_window = Window::Create(WindowProps("Window", 1024, 768));

		WindowsInput::s_Instance->StartUp((GLFWwindow*)_window->GetNativeWindow());
		Renderer::GetInstance().StartUp();

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
			Renderer::GetRendererAPI().SetClearColor(glm::vec4(1));
			Renderer::GetRendererAPI().Clear();

			// source->playSource(&buffer); 
			
			//Update renderer.
			model->Draw(*shader);

			//Draw UI

			//Swap front and back buffers 
			
			_window->OnUpdate();
		};
	}
}

