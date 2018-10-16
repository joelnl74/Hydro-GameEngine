#pragma once
#include "../vendor/imgui/imgui.h"
class Input
{
private:
	/* Here will be the instance stored. */
	static Input* instance;
	ImGuiIO &io = ImGui::GetIO();
	/* Private constructor to prevent instancing. */
	Input();

public:
	bool Input::IsKeyDown(ImGuiKey key)
	{
		if (ImGui::IsKeyDown(key))
		{
			return true;
		}
		return false;
	}
	bool Input::MouseClicked(int MouseClick)
	{
		if (io.MouseClicked[MouseClick] == true)
		{
			return true;
		}
		return false;
	}
	/* Static access method. */
	static Input* getInstance();

};

/* Null, because instance will be initialized on demand. */
Input* Input::instance = 0;

Input* Input::getInstance()
{
	if (instance == 0)
	{
		instance = new Input();
	}

	return instance;
}

Input::Input()
{
}


