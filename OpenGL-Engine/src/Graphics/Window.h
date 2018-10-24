#pragma once
#include <iostream>

#include "GL\glew.h"
#include <GLFW\glfw3.h>

#define MAX_KEYS	1024
#define MAX_BUTTONS 32

//Create a window context with GLFW
class Window
{
public:
	Window(const int &WINDOW_WIDTH, const int &WINDOW_HEIGHT, const char *WINDOW_NAME);
	~Window();
	void update();
	void clear() const;
	bool closed() const;

	inline GLFWwindow* getWindow() const { return m_Window; }
	static bool isKeyPressed(int keycode);
	static bool isMouseButtonPressed(unsigned int button);
private:
	friend struct  GLFWindow;

	GLFWwindow *m_Window;
	int m_Width, m_Height;
	const char *m_Title;

	static bool m_keys[MAX_KEYS];
	static bool m_MouseButtons[MAX_BUTTONS];
private:
	bool Init();
	friend static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
	friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};


