#pragma once
#include <string>

#include "Window.h"

int main(int argc, char** argv);

namespace Hydro
{
	class Application
	{
	public:
		Application(const std::string& name = "Hazel App");

		Window& GetWindow() { return *m_Window; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
	private:
		Window* m_Window;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	Application* CreateApplication();
}