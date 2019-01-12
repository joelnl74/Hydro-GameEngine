#pragma once
#include "./Layer.h"

#include <map>

class LayerManager
{
public:
	LayerManager();
	~LayerManager();
	void DrawLayers();
	void ClearLayers();
	void RemoveLayer(int id);
	void AddLayer(bool static_layer = true);
	//TODO log error that this layer doesnt exsist, and handle the error in some way
	inline Layer* getLayer(int id) { return m_layerManager.at(id); }
	std::map<int, Layer*> *getManager() { return &m_layerManager; }
private:
	std::map<int, Layer*> m_layerManager;
};

