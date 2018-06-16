#include "EditorUI.h"

EditorUI::EditorUI(GLFWwindow *win, LayerManager* _manager)
{
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(win, true);
	ImGui::StyleColorsLight();

	m_layerManager = _manager;
}

EditorUI::~EditorUI()
{
	delete selectedSprite;
}
void EditorUI::setSelectedSprite(Sprite *sprite)
{
	selectedSprite = sprite;

	position[0] = selectedSprite->getPosition().x;
	position[1] = selectedSprite->getPosition().y;

	uv[0] = selectedSprite->getUV().x * 4;
	uv[1] = selectedSprite->getUV().y * 4;

	scale[0] = selectedSprite->getScale().x;
	scale[1] = selectedSprite->getScale().y;
}
void EditorUI::DrawUI()
{

	ImGui_ImplGlfwGL3_NewFrame();
	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("New"))
		{
			//clear scene
		}
		if (ImGui::MenuItem("Save")) 
		{
			//Save current level to a xml file or something like that
		}
		if (ImGui::MenuItem("Load")) 
		{
			//load a level from a xml file or something like that
		} 
		if (ImGui::MenuItem("Exit")) 
		{
			//close the engine and ask if someone wants to save their progress before quiting the engine
		}
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Sprite"))
	{
		if (ImGui::MenuItem("EditSprite", NULL, &spriteEditor))
		{
			//GetSelected sprite if none return a nullptr and disable sprite editor again
			printf("Opened Sprite editor");
		}
		if (ImGui::MenuItem("CreateSprite", NULL, &spriteCreator))
		{
			//Opend sprite creator, Create a new sprite and add it to a layer to draw
		}
		ImGui::EndMenu();
	}
	ImGui::MenuItem("Play", NULL, &play);
	ImGui::EndMainMenuBar();

	if (spriteEditor == true && !play || spriteCreator == true && !play)
	{
		ImGui::Begin("SpriteEditor");

		ImGui::Text("SpritePosition");
		ImGui::InputFloat2("", position);

		ImGui::Text("SpriteSize");
		ImGui::InputFloat2(" ", scale);

		ImGui::Text("UV");
		ImGui::InputFloat2("  ", uv);

		if (ImGui::Button("Submit", ImVec2(50, 50)))
		{
			if (spriteEditor)
			{
				selectedSprite->setPosition(position[0], position[1]);
				selectedSprite->Scale(scale[0], scale[1]);
				selectedSprite->setTextureUV(uv[0], uv[1]);
			}
			else if (spriteCreator)
			{
				Sprite * sprite = new Sprite(scale[0], scale[1], position[0], position[1]);
				//set uv
				sprite->setIndex(4, 4);
				//set texture
				sprite->setTextureUV(uv[0], uv[1]);
				//add to selected layer
				m_layerManager->getLayer(0)->submitSprite(*sprite);
			}
		}
		ImGui::End();
	}
	ImGui::Render();
	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}