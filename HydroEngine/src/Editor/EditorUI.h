#pragma once
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw_gl3.h"
#include "../Graphics/RenderManager.h"

class EditorUI
{
public:
	EditorUI(GLFWwindow *win);
	~EditorUI();
	void setSelectedSprite(Sprite *sprite);
	void SpriteEditor();
	void DrawUI();
	void MainBar();
	void Inspector();
	void CreateSprite();
	bool PaintSprite(float x, float y);
	bool returnPlay() { return play; }
	int returnSelectedLayer() {return layerID; }

	bool spritePlacementMode = false;
private:
	bool play = false;
	bool solid = false;
	bool inspector = true;
	//temp
	bool spriteEditor = false;
	bool spriteCreator = false;

	bool isHovered = false;

	Sprite *selectedSprite = nullptr;
	RenderManager &gRenderManager = RenderManager::GetInstance();

	float offset[2];
	float position[2];
	float scale[2];
	float uv[2];
	int layerID;
};

