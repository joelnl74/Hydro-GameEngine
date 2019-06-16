#pragma once
#include <iostream>

#include "GL\glew.h"
#include <GLFW\glfw3.h>

namespace Hydro
{
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
	private:
		friend struct  GLFWindow;

		GLFWwindow *m_Window;
		int m_Width, m_Height;
		const char *m_Title;

	private:
		bool Init();
	};
}



