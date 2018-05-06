#pragma once
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw_gl3.h"

#include "../Graphics/Window.h"
#include "../Graphics/Sprite.h"

class EditorUI
{
public:
	EditorUI(GLFWwindow *win);
	~EditorUI();
	void DrawUI(Sprite &sprite);
	bool returnPlay() { return play; }
private:
	bool play = false;
	bool spriteEditor = false;

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	float position[2];
	float scale[2];
	float uv[2];

};

