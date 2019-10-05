#pragma once
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw_gl3.h"

namespace Hydro
{
	class EditorUI
	{
	public:
		EditorUI(GLFWwindow *win);
		~EditorUI();
		void DrawUI();
		void MainBar();
		void Inspector();
		bool returnPlay() { return play; }

		bool spritePlacementMode = false;
	private:
		bool play = false;
		bool spriteEditor = false;
		bool isHovered = false;

		bool inspector = true;
	};
}

