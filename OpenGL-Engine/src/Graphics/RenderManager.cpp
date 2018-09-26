#include "RenderManager.h"
RenderManager *RenderManager::s_instance = 0;

void RenderManager::StartUp()
{
	if (s_instance == 0)
	{
		s_instance = new RenderManager();
		s_instance->createObjects();
		s_instance->shader->Bind();
	}
}
void RenderManager::ShutDown()
{
	delete s_instance->_layerManager;
	delete s_instance->shader;
	delete s_instance;
}