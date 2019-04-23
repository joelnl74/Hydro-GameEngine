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
		_editUI = hnew EditorUI(_window->getWindow());
		WindowsInput::GetInstance().StartUp(_window->getWindow());
		RenderManager::GetInstance().StartUp();

		_audio = hnew AudioManager();
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
		hdel _audio;
		hdel _camera;

		gTime.ShutDown();
		Logger::m_Instance->ShutDown();
		WindowsInput::GetInstance().ShutDown();
		hdel _window;

	}
	void HydroEngine::MainLoop()
	{
		//Clear Screen
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);;

		source->playSource(&buffer);

		//update systems

		//Draw UI
		_editUI->DrawUI();
		// Swap front and back buffers 
		_window->update();
	};