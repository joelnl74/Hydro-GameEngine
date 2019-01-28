#pragma once
#include "Shader.h"
#include "layering/LayerManager.h"
class RenderManager
{
public:
	LayerManager * _layerManager;
	Shader *shader;

	//startup this subsystem of the engine
	void StartUp();
	//close this subsystem of the engine
	void ShutDown();
	//Draw every layer
	void Update()
	{
		m_instance->_layerManager->DrawLayers();
	}
	inline static RenderManager &GetInstance()
	{
		return *m_instance;
	}
private:
	static RenderManager *m_instance;
};





