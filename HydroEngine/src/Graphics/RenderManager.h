#pragma once
#include "Shader.h"
#include "Camera.h"
#include "spriteBatch.h"

//TODO REMOVE THIS CLASS
class RenderManager
{
public:
	Shader *shader;
	Camera *_camera;
	spriteBatch *_spriteBatch;

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





