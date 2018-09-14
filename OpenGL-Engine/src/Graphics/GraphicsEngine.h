#pragma once
#include "Shader.h"
#include "layering/LayerManager.h"
class GraphicsEngine
{
public:
	void StartUp();
	void ShutDown();
	void Update();

	LayerManager* _layerManager;
	Shader *shader;
};

