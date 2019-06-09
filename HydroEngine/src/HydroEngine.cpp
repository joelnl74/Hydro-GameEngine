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
		_window = new Window(WIDTH, HEIGHT, "Hydro-Engine");
		RenderManager::GetInstance().StartUp();
		WindowsInput::s_Instance->StartUp(_window->getWindow());
		_editUI = hnew EditorUI(_window->getWindow());

		_audio = new AudioManager();
		_audio->Init();
		_audio->SetListener();

		buffer = _audio->LoadAudioSound("Resources/sounds/Hydro_Engine_Sound1.ogg");

		source = new AudioSource();
		source->Init(0, 0, 0, 1, 1, buffer);
	}
	HydroEngine::~HydroEngine()
	{
		RenderManager::GetInstance().ShutDown();
		//clear memory
		_audio->CleanUp();
		delete _audio;
		delete _camera;

		gTime.ShutDown();
		Logger::m_Instance->ShutDown();
		delete _window;

	}
	void HydroEngine::MainLoop()
	{
		//Clear Screen
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);;

		if (WindowsInput::s_Instance->IsKeyPressed(HY_KEY_W))
		{
			std::cout << "W pressed" << std::endl;
		}

		source->playSource(&buffer);

		//update systems

		//Draw UI
		_editUI->DrawUI();
		// Swap front and back buffers 
		_window->update();
	};