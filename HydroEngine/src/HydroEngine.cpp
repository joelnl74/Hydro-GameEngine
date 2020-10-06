#include "HydroEngine.h"

#include <GLFW/glfw3.h>
#include "Renderer/RenderCommand.h"
#include "Renderer/Renderer2D.h";
namespace Hydro
{
	//Only Start major parts of the engine later on here so change Camera editor Window all to the graphics part of the engine
	HydroEngine::HydroEngine()
	{
		Logger::Init();
		Time::m_Instance->StartUp();
		
		_window = Window::Create(WindowProps("Window", 1024, 768));
		_camera = new Camera(800, 600, orthographic);

		WindowsInput::s_Instance->StartUp((GLFWwindow*)_window->GetNativeWindow());
		Renderer::StartUp();

		_audio = new AudioManager();
		_audio->Init();
		_audio->SetListener();

		buffer = _audio->LoadAudioSound("Resources/sounds/Hydro_Engine_Sound1.ogg");

		source = new AudioSource();
		source->Init(0, 0, 0, 1, 1, buffer);

		RenderCommand::SetClearColor(glm::vec4(0, 0, 0, 1));
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
			RenderCommand::Clear();

			// source->playSource(&buffer); 
			
			//Update renderer.
			//model->Draw(*shader);
			Renderer2D::BeginScene(_camera->ReturnViewProjection());
			Renderer2D::DrawQuad({ 0, 0, 0.5f }, { 250,  250}, { 0.8f, 0.2f, 0.3f, 1.0f });
			Renderer2D::EndScene();
			//Draw UI

			//Swap front and back buffers 
			
			_window->OnUpdate();
		};
	}
}

