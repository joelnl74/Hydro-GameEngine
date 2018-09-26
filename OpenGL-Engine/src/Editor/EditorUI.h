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
	int returnSelectedLayer() {return layerID; }
	bool returnPlay() { return play; }

	bool spritePlacementMode = false;
private:
	Sprite *selectedSprite = nullptr;
	RenderManager &gRenderManager = RenderManager::GetInstance();
	bool isHovered = false;

	bool play = false;
	bool solid = false;
	bool inspector = true;
	//temp
	bool spriteEditor = false;
	bool spriteCreator = false;

	int offset[2];
	int position[2];
	int scale[2];
	int uv[2];
	int layerID;
};

