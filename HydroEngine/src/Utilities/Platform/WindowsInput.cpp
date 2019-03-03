#include "WindowsInput.h"
#include <GLFW/glfw3.h>
Input* Input::s_Instance = new WindowsInput();

bool WindowsInput::IsKeyPressedImpl(int keycode)
{
	//get window, get button state return state
	return false;
}

bool WindowsInput::IsMouseButtonPressedImpl(int button)
{
	//get window, get button state return state

	return false;
}

std::pair<float, float> WindowsInput::GetMousePositionImpl()
{
	//get window, get button state return state
	return std::pair<float, float>();
}

float WindowsInput::GetMouseXImpl()
{
	//get window, get button state return state
	return 0.0f;
}

float WindowsInput::GetMouseYImpl()
{
	//get window, get button state return state
	return 0.0f;
}
