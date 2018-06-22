#pragma once
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw_gl3.h"

#include "../Graphics/Window.h"
#include "../Graphics/layering/LayerManager.h"

class EditorUI
{
public:
	EditorUI(GLFWwindow *win, LayerManager* _manager);
	~EditorUI();
	void setSelectedSprite(Sprite *sprite);
	void SpriteEditor();
	void DrawUI();
	bool returnPlay() { return play; }
private:
	LayerManager * m_layerManager = nullptr;
	Sprite *selectedSprite = nullptr;

	bool play = false;
	bool spriteEditor = false;
	bool spriteCreator = false;

	float position[2];
	float scale[2];
	float uv[2];
	int layerID;

};

