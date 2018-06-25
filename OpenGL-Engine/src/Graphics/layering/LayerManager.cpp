#include "LayerManager.h"



LayerManager::LayerManager()
{
}
LayerManager::~LayerManager()
{
	for (std::map<int, Layer*>::iterator it = m_layerManager.begin(); it != m_layerManager.end(); it++)
	{
	    it->second->~Layer();
		delete it->second;
	}
	m_layerManager.clear();
}
void LayerManager::addLayer()
{
	Layer* _layer = new Layer();

	if(m_layerManager.begin() != m_layerManager.end())
	m_layerManager.emplace(m_layerManager.size() , _layer);
	else
	{
		m_layerManager.emplace(0, _layer);
	}
}
void LayerManager::drawLayers()
{
	for (std::map<int, Layer*>::iterator it = m_layerManager.begin(); it != m_layerManager.end(); it++)
	{
		it->second->drawBatch();
	}
}