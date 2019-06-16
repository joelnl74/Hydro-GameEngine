#include "Engine.h"

Engine::Engine()
{
	m_engine = hnew Hydro::HydroEngine();
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
		Time::m_Instance->BeginFrame();
		//Render here 
		m_engine->MainLoop();
		//end of frame
		Time::m_Instance->EndFrame();

		MemoryManager::Get()->GetMemoryStats();
	}
}