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
		Window(const int &width, const int &height, const char *name);
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



