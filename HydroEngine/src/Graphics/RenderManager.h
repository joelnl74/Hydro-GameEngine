#pragma once
#include "Shader.h"
#include "Camera.h"
#include "layering/LayerManager.h"

//TODO REMOVE THIS CLASS
class RenderManager
{
public:
	LayerManager * _layerManager;
	Shader *shader;
	Camera *_camera;

	//startup this subsystem of the engine
	void StartUp();
	//close this subsystem of the engine
	void ShutDown();

	inline static RenderManager &GetInstance()
	{
		return *m_instance;
	}
private:
	static RenderManager *m_instance;
};





