#include "Engine.h"

Engine::Engine()
{
	m_engine = hnew HY_Engine::HydroEngine();
}
Engine::~Engine()
{
	hdel m_engine;
}

void Engine::Run()
{
	//Gameloop 
	while (!m_engine->_window->closed())
	{
		//Begin of frame
		m_engine->gTime.m_Instance->BeginFrame();
		//create own Interaction class for UI and Gameplay
		m_engine->CheckInput();
		//Render here 
		m_engine->Draw();
		//end of frame
		m_engine->gTime.m_Instance->EndFrame();

		MemoryManager::Get()->GetMemoryStats();
	}
}