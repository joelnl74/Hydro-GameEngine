#include "EditorUI.h"
#include <stdio.h>
#include "../RescourceManagement/SceneManager/SceneManager.h"
EditorUI::EditorUI(GLFWwindow *win)
{
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(win, true);
	ImGui::StyleColorsLight();
}
EditorUI::~EditorUI()
{
}
void EditorUI::setSelectedSprite(Sprite *sprite)
{
	if (sprite != nullptr && !spritePlacementMode)
	{
		selectedSprite = sprite;

		position[0] = selectedSprite->getPosition().x;
		position[1] = selectedSprite->getPosition().y;

		uv[0] = selectedSprite->getUV().x * 4;
		uv[1] = selectedSprite->getUV().y * 4;

		scale[0] = selectedSprite->getScale().x;
		scale[1] = selectedSprite->getScale().y;
	}
}
bool EditorUI::PaintSprite(float x, float y)
{
	x = x - scale[0];
	y = y - scale[1];

	position[0] = x;
	position[1] = y;

	if (offset[0] != 0 && offset[1] != 0)
	{
		if (position[0] % offset[0] == 0 && position[1] % offset[1] == 0)
		{
			CreateSprite();
		}
		else
		{
			float i = position[0] % offset[0];
			float j = position[1] % offset[1];

			if (position[0] > 0)
			{
				position[0] = position[0] - i;
			}
			else
			{
				position[0] = position[0] + -i;
			}
			if (position[1] > 0)
			{
				position[1] = position[1] - j;
			}
			else
			{
				position[1] = position[1] + -j;
			}
			CreateSprite();
			return true;
		}
	}
	CreateSprite();
	return true;
}
void EditorUI::DrawUI()
{
	ImGui_ImplGlfwGL3_NewFrame();
	MainBar();
	Inspector();
	SpriteEditor();
	ImGui::Render();
	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}
void EditorUI::SpriteEditor()
{
	if (spriteEditor == true && !play)
	{
		ImGui::Begin("SpriteEditor");
		ImGui::Text("SpritePosition");
		ImGui::InputInt2("", position);

		ImGui::Text("SpriteSize");
		ImGui::InputInt2(" ", scale);

		ImGui::Text("UV");
		ImGui::InputInt2("  ", uv);

		ImGui::Text("Solid");
		ImGui::SameLine();
		ImGui::Checkbox("     ", &solid);

		ImGui::Text("Paint");
		ImGui::SameLine();
		ImGui::Checkbox("      ", &spritePlacementMode);

		ImGui::Text("Offset");
		ImGui::SameLine();
		ImGui::InputInt2("      ", offset);

		ImGui::Text("Layer");
		ImGui::InputInt("    ", &layerID);

		if (ImGui::Button("Change", ImVec2(50, 50)) && selectedSprite != nullptr)
		{
			selectedSprite->setPosition(position[0], position[1]);
			selectedSprite->Scale(scale[0], scale[1]);
			selectedSprite->setTextureUV(uv[0], uv[1]);
			selectedSprite->setSolid(&solid);

			gRenderManager._layerManager->getLayer(layerID)->SubmitLayer();
		}
		ImGui::SameLine();
		if (ImGui::Button("Create", ImVec2(50, 50)))
		{
			if (gRenderManager._layerManager->getLayer(layerID))
			{
				CreateSprite();
			}
			else
				//TODO FIX WHEN I HAVE A LOGGING SYSTEM
				printf("This layer does not exsist! ");
		}
		ImGui::SameLine();
		if (ImGui::Button("Layer", ImVec2(50, 50)) && selectedSprite != nullptr)
		{
			//TODO get layer from sprite
			gRenderManager._layerManager->getLayer(0)->RemoveSprite(selectedSprite);
			gRenderManager._layerManager->getLayer(layerID)->SubmitSprite(*selectedSprite);
		}
		ImGui::End();
	}
}
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
			SceneManager manager;
			manager.saveScene("res/scene/Testlevel.json", gRenderManager._layerManager);
		}
		//load a scene from a json file
		if (ImGui::MenuItem("Load"))
		{
			SceneManager manager;
			manager.loadScene("res/scene/Testlevel.json", gRenderManager._layerManager);
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
void EditorUI::CreateSprite()
{
	//create sprite object with filled in variabels, probally dont wanna do this because calling new is expensive, need to make a custom memory manager, which creates a block of memory which i can ask for and set a pointer to a piece of memory
	Sprite * sprite = new Sprite(scale[0], scale[1], position[0], position[1], &solid);
	//set uv
	sprite->setIndex(4, 4);
	//set texture
	sprite->setTextureUV(uv[0], uv[1]);
	//add to selected layer
	gRenderManager._layerManager->getLayer(layerID)->SubmitSprite(*sprite);
	//selectedSprite = new created sprite
	setSelectedSprite(sprite);
}
void EditorUI::Inspector()
{
	//TODO: Hard coded, change to getting windowsize from main engine class or settings
	ImGui::SetNextWindowPos(ImVec2(1024 -  200, 18));
	ImGui::SetNextWindowSize(ImVec2(200, 780));
	ImGui::Begin("Inspector");
	ImGui::Text("Position");
	ImGui::InputInt2("", position);

	ImGui::Text("Scale");
	ImGui::InputInt2(" ", scale);
	ImGui::End();
}