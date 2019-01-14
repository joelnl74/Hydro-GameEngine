#pragma once
#include "SpriteEditor.h"
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw_gl3.h"
#include "../Graphics/RenderManager.h"

class EditorUI
{
public:
	EditorUI(GLFWwindow *win);
	~EditorUI();
	void DrawUI();
	void MainBar();
	void Inspector();
	int returnSelectedLayer() {return layerID; }
	bool returnPlay() { return play; }

	SpriteEditor* _spriteEditor;
	bool spritePlacementMode = false;
private:
	bool play = false;
	bool spriteEditor = false;
	bool isHovered = false;

	bool inspector = true;

	Sprite *selectedSprite = nullptr;
	RenderManager &gRenderManager = RenderManager::GetInstance();
	int layerID;
};
