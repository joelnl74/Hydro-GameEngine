#pragma once
#include "Shader.h"
#include "layering/LayerManager.h"
class RenderManager
{
public:
	LayerManager * _layerManager;
	Shader *shader;

	void CreateObjects()
	{
		_layerManager = new LayerManager();
		shader = new Shader("Resources/shaders/Basic.shader");
	}
	//startup this subsystem of the engine
	void StartUp();
	//close this subsystem of the engine
	void ShutDown();
	//Draw every layer
	void Update()
	{
		s_instance->_layerManager->DrawLayers();
	}
	inline static RenderManager &GetInstance()
	{
		return *s_instance;
	}
private:
	static RenderManager *s_instance;
};





