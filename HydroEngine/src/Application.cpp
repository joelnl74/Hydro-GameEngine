#include "HydroEngine.h"
/*
All the code in Application is dummy code just to test some parts of the engine
With right mouse click you can select sprites
Within the spriteEditor you can change properties of the selected sprite
Play makes it possible to move your character sprite around the screen
*/

int main()
{
	//create a window
	Engine::HydroEngine* m_engine = hnew Engine::HydroEngine();

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
	//delete engine
	hdel m_engine;
	return 0;
}

