#include "HydroEngine.h"
#include "Editor/EditorUI.h"
static const int WIDTH = 1024;
static const int HEIGHT = 768;

namespace Hydro
{
	//Only Start major parts of the engine later on here so change Camera editor Window all to the graphics part of the engine
	HydroEngine::HydroEngine()
	{
		Logger::m_Instance->StartUp();
		Time::m_Instance->StartUp();
		_window = hnew Window(WIDTH, HEIGHT, "Hydro Engine");
		RenderManager::GetInstance().StartUp();
		WindowsInput::s_Instance->StartUp(_window->getWindow());
		World::GetInstance().StartUp();
		_editUI = hnew EditorUI(_window->getWindow());

		_audio = hnew AudioManager();
		_audio->Init();
		_audio->SetListener();

		buffer = _audio->LoadAudioSound("Resources/sounds/Hydro_Engine_Sound1.ogg");

		source = hnew AudioSource();
		source->Init(0, 0, 0, 1, 1, buffer);

		FBX *fbx = hnew FBX();
		bool setup = fbx->Setup();
	}
	HydroEngine::~HydroEngine()
	{
		World::GetInstance().ShutDown();
		RenderManager::GetInstance().ShutDown();
		//clear memory
		_audio->CleanUp();
		hdel _audio;
		hdel _camera;

		Time::m_Instance->ShutDown();
		Logger::m_Instance->ShutDown();
		hdel _window;

	}
	void HydroEngine::MainLoop()
	{
		//Clear Screen
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);;

		source->playSource(&buffer);

		//update systems
		RenderManager::GetInstance().m_spriteBatch->Begin();
		World::GetInstance().Update();
		RenderManager::GetInstance().m_spriteBatch->End();
		RenderManager::GetInstance().m_spriteBatch->Flush();

		//Draw UI
		//_editUI->DrawUI();
		// Swap front and back buffers 
		_window->update();
	};
}

