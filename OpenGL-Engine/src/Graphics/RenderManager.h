#pragma once
#include "Shader.h"
#include "layering/LayerManager.h"
class RenderManager
{
public:
	LayerManager * _layerManager;
	Shader *shader;


	void createObjects()
	{
		_layerManager = new LayerManager();
		shader = new Shader("res/shaders/Basic.shader");
	}
	//startup this subsystem of the engine
	void StartUp()
	{
		if (s_instance == 0)
		{
			s_instance = new RenderManager();
			s_instance->createObjects();
			s_instance->shader->Bind();
		}
	}
	//close this subsystem of the engine
	void ShutDown()
	{
		delete s_instance->_layerManager;
		delete s_instance->shader;
		delete s_instance;
	}
	void Update()
	{
		_layerManager->DrawLayers();
	}
	inline static RenderManager &Get()
	{
		return *s_instance;
	}
private:
	//RenderManager();
	static RenderManager *s_instance;
};





