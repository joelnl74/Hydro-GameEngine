#include "LayerManager.h"



LayerManager::LayerManager()
{
	//add the base layer for the engine to draw to
	//TODO (temp fix) needs to be set in a graphics engine class or so
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCall(glEnable(GL_BLEND));
	AddLayer();
}
LayerManager::~LayerManager()
{
	for (std::map<int, Layer*>::iterator it = m_layerManager.begin(); it != m_layerManager.end(); it++)
	{
		delete it->second;
	}
	m_layerManager.clear();
}
void LayerManager::AddLayer(bool static_layer)
{
	Layer* _layer = hnew Layer(static_layer);

	if(m_layerManager.begin() != m_layerManager.end())
	m_layerManager.emplace(m_layerManager.size() , _layer);
	else
	{
		m_layerManager.emplace(0, _layer);
	}
}
void LayerManager::DrawLayers()
{
	for (std::map<int, Layer*>::iterator it = m_layerManager.begin(); it != m_layerManager.end(); it++)
	{
		it->second->DrawBatch();
	}
}
void LayerManager::ClearLayers()
{
}
void LayerManager::RemoveLayer(int id)
{
	for (std::map<int, Layer*>::iterator it = m_layerManager.begin(); it != m_layerManager.end(); it++)
	{
		if (it->first == id)
		{
			//clear all sprites on this layer
		}
	}
}