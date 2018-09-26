#include "Editor.h"
Editor::Editor(GLFWwindow *win, Camera *camera)
{
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(win, true);
	ImGui::StyleColorsLight();
	ui = new EditorUI(win);
	_camera = camera;
}


Editor::~Editor()
{
	delete ui;
}

void Editor::UpdateInput()
{
	//TODO change to input class
	ImGuiIO & io = ImGui::GetIO();
	if (io.MouseClicked[0] == true && ImGui::IsAnyItemHovered() == false && ui->spritePlacementMode == false)
	{
		float xPosition = 720.0f / 1024.0f;
		float yPosition = 480.0f / 768.0f;
		ui->setSelectedSprite(RenderManager::GetInstance()._layerManager->getLayer(ui->returnSelectedLayer())->ReturnSprite(_camera->returnWorldToCameraPosition().x, _camera->returnWorldToCameraPosition().y));
	}
	else if (ui->spritePlacementMode == true && io.MouseClicked[0] == true && ImGui::IsAnyItemHovered() == false)
	{
		ui->PaintSprite(_camera->returnWorldToCameraPosition().x,_camera->returnWorldToCameraPosition().y);
	}
}