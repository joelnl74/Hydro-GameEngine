#include "LayerManager.h"



LayerManager::LayerManager()
{
}
LayerManager::~LayerManager()
{
}
void LayerManager::addLayer(int id)
{
	Layer* _layer = new Layer();
	m_layerManager.emplace(0, _layer);
}
void LayerManager::drawLayers()
{
	for (std::map<int, Layer*>::iterator it = m_layerManager.begin(); it != m_layerManager.end(); it++)
	{
		it->second->drawBatch();
	}
}