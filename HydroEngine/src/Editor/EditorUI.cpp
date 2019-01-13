#include "EditorUI.h"
#include <stdio.h>
#include "../RescourceManagement/SceneManager/LevelLoader2D.h"
EditorUI::EditorUI(GLFWwindow *win)
{
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(win, true);
	ImGui::StyleColorsLight();
	layerID = 0;
	_spriteEditor = hnew SpriteEditor();
}
EditorUI::~EditorUI()
{
	hdel _spriteEditor;
}
void EditorUI::DrawUI()
{
	ImGui_ImplGlfwGL3_NewFrame();
	MainBar();
	Inspector();
	_spriteEditor->M_SpriteEditor(gRenderManager, play, spriteEditor);
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
			LevelLoader2D loader;
			loader.saveScene("Resources/scene/Testlevel.json", gRenderManager._layerManager);
		}
		//load a scene from a json file
		if (ImGui::MenuItem("Load"))
		{
			LevelLoader2D loader;
			loader.loadScene("Resources/scene/Testlevel.json", gRenderManager._layerManager);
		}
		if (ImGui::MenuItem("Exit"))
		{
			//close the engine and ask if someone wants to save their progress before quiting the engine
		}
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Sprite"))
	{
		if (ImGui::MenuItem("SpriteEditor", NULL, &spriteEditor))
		{
			_spriteEditor->M_SpriteEditor(gRenderManager, play, spriteEditor);
		}
		if (ImGui::MenuItem("Add Layer"))
		{
			gRenderManager._layerManager->AddLayer();
		}
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
	//ImGui::Text("Position");
	//ImGui::InputFloat2("", position);

	//ImGui::Text("Scale");
	//ImGui::InputFloat2(" ", scale);
	ImGui::Text(MemoryManager::Get()->BytesToString(MemoryManager::Get()->GetMemoryStats().currentUsed).data());
	ImGui::End();
}