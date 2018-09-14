#include "GraphicsEngine.h"

void GraphicsEngine::StartUp()
{
	_layerManager = new LayerManager();
	//TODO change placing of the shader so other classes that need it can reach it also
	shader = new Shader("res/shaders/Basic.shader");
	shader->Bind();
}
void GraphicsEngine::ShutDown()
{
	delete _layerManager;
	delete shader;
}
void GraphicsEngine::Update()
{
	_layerManager->DrawLayers();
}
