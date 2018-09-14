#pragma once
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw_gl3.h"
#include "../Graphics/Window.h"
#include "../Graphics/GraphicsEngine.h"

class EditorUI
{
public:
	EditorUI(GLFWwindow *win, GraphicsEngine* _manager);
	~EditorUI();
	void setSelectedSprite(Sprite *sprite);
	void SpriteEditor();
	void DrawUI();
	void MainBar();
	void Inspector();
	void CreateSprite();
	bool EditorUI::PaintSprite(float x, float y);
	int returnSelectedLayer() {return layerID; }
	bool returnPlay() { return play; }

	GraphicsEngine * _graphicsEngine = nullptr;
	bool spritePlacementMode = false;
private:
	Sprite *selectedSprite = nullptr;
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

