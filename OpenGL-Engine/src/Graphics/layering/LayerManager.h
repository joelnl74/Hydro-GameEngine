#pragma once
#include "./Layer.h"

#include <map>

class LayerManager
{
public:
	LayerManager();
	~LayerManager();
	void drawLayers();

	void addLayer(int id);
	inline Layer* getLayer(int id) { return m_layerManager.at(id); }
private:
	std::map<int, Layer*> m_layerManager;
};

