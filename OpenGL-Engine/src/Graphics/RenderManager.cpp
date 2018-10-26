#include "RenderManager.h"
RenderManager *RenderManager::m_instance = 0;

void RenderManager::StartUp()
{
	if (m_instance == 0)
	{
		m_instance = new RenderManager();
		m_instance->_layerManager = new LayerManager();
		m_instance->shader = new Shader("Resources/shaders/Basic.shader");
		m_instance->shader->Bind();
	}
}
void RenderManager::ShutDown()
{
	delete m_instance->_layerManager;
	delete m_instance->shader;
	delete m_instance;
}