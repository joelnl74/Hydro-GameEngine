#include "RenderManager.h"
RenderManager *RenderManager::m_instance = 0;

void RenderManager::StartUp()
{
	if (m_instance == 0)
	{
		m_instance = hnew RenderManager();
		m_instance->_layerManager = hnew LayerManager();
		m_instance->shader = hnew Shader("Resources/shaders/Basic.shader");
		m_instance->shader->Bind();
	}
}
void RenderManager::ShutDown()
{
	hdel m_instance->_layerManager;
	hdel m_instance->shader;
	hdel m_instance;
}