#include "SpriteEditor.h"
#include "../Hydro.h"
#include "../vendor/imgui/imgui.h"

SpriteEditor::SpriteEditor()
{
}


SpriteEditor::~SpriteEditor()
{
}
//TODO Remove this function and change it to get an entity in the scene
void SpriteEditor::setSelectedSprite(Sprite *sprite)
{
	if (sprite != nullptr && !spritePlacementMode)
	{
		selectedSprite = sprite;

		position[0] = selectedSprite->getPosition().x;
		position[1] = selectedSprite->getPosition().y;
		//TODO HARDCODED
		uv[0] = selectedSprite->getUV().x * 4;
		uv[1] = selectedSprite->getUV().y * 4;

		scale[0] = selectedSprite->getScale().x;
		scale[1] = selectedSprite->getScale().y;
	}
}
//SpriteEditorUI
void SpriteEditor::M_SpriteEditor(RenderManager &gRenderManager, bool play, bool spriteEditor)
{
	if (spriteEditor == true && !play)
	{
		ImGui::Begin("SpriteEditor");
		ImGui::Text("SpritePosition");
		ImGui::InputFloat2("", position);

		ImGui::Text("SpriteSize");
		ImGui::InputFloat2(" ", scale);

		ImGui::Text("UV");
		ImGui::InputFloat2("  ", uv);

		ImGui::Text("Solid");
		ImGui::SameLine();
		ImGui::Checkbox("     ", &solid);

		ImGui::Text("Paint");
		ImGui::SameLine();
		ImGui::Checkbox("      ", &spritePlacementMode);

		ImGui::Text("Offset");
		ImGui::SameLine();
		ImGui::InputFloat2("      ", offset);

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
				CreateSprite(gRenderManager);
			}
			else
				LOG_DEBUG("This layer doesn't exsist! ");
		}
		ImGui::SameLine();
		if (ImGui::Button("Layer", ImVec2(50, 50)) && selectedSprite != nullptr)
		{
			//TODO Remove sprite and do things based on Entities
			gRenderManager._layerManager->getLayer(0)->RemoveSprite(selectedSprite);
			gRenderManager._layerManager->getLayer(layerID)->SubmitSprite(*selectedSprite);
		}
		ImGui::End();
	}
}
//Create Sprite
void SpriteEditor::CreateSprite(RenderManager &gRenderManager)
{
	//create a entity object

	//Create a sprite component and add it to the just created entity
	Sprite * sprite = hnew Sprite(scale[0], scale[1], position[0], position[1], &solid);

	//Set sprite information
	//------------------------------------------------------------------------------------
	sprite->setIndex(4, 4);
	sprite->setTextureUV(uv[0], uv[1]);
	//TODO Remove this an component should add itself to the right system
	gRenderManager._layerManager->getLayer(layerID)->SubmitSprite(*sprite);
	//Selected gameobject = this
	setSelectedSprite(sprite);
}