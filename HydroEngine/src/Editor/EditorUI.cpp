#include "EditorUI.h"
#include <stdio.h>
#include "../RescourceManagement/SceneManager/LevelLoader2D.h"
EditorUI::EditorUI(GLFWwindow *win)
{
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(win, true);
	ImGui::StyleColorsLight();
	layerID = 0;
}
EditorUI::~EditorUI()
{
}
void EditorUI::DrawUI()
{
	ImGui_ImplGlfwGL3_NewFrame();
	MainBar();
	Inspector();
	ImGui::Render();
	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}
//Handling header bar opening and closing windows
void EditorUI::MainBar()
{
	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("New"))
		{
			gRenderManager._layerManager->getLayer(0)->DeleteLayer();
		}
		//Save current scene to a json file 
		if (ImGui::MenuItem("Save"))
		{

		}
		//load a scene from a json file
		if (ImGui::MenuItem("Load"))
		{

		}
		if (ImGui::MenuItem("Exit"))
		{
			//close the engine and ask if someone wants to save their progress before quiting the engine
		}
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Sprite"))
	{
		ImGui::EndMenu();
	}
	ImGui::MenuItem("Play", NULL, &play);
	ImGui::EndMainMenuBar();
}
void EditorUI::Inspector()
{
	//TODO: Hard coded, change to getting windowsize from main engine class or settings
	ImGui::SetNextWindowPos(ImVec2(1024 -  200, 18));
	ImGui::SetNextWindowSize(ImVec2(200, 780));
	ImGui::Begin("Inspector");

	ImGui::Text(MemoryManager::Get()->BytesToString(MemoryManager::Get()->GetMemoryStats().currentUsed).data());
	ImGui::End();
}