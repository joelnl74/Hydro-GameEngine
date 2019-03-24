#include "WindowsInput.h"
#include "../../Hydro.h"

Input *Input::s_Instance = 0;

bool WindowsInput::IsKeyPressedImpl(int keycode)
{
	auto state = glfwGetKey(window, keycode);

	//get window, get button state return state
	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool WindowsInput::IsMouseButtonPressedImpl(int button)
{
	auto state = glfwGetMouseButton(window, button);

	//get window, get button state return state
	return state == GLFW_PRESS;
}

std::pair<float, float> WindowsInput::GetMousePositionImpl()
{
	double x, y;

	glfwGetCursorPos(window, &x, &y);
	//get window, get button state return state
	return { (float)x, (float)y };
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

void WindowsInput::StartUp(GLFWwindow * _window)
{
	s_Instance = hnew WindowsInput();
	s_Instance->window = _window;
}

void WindowsInput::ShutDown()
{
}
