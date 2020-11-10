#include "Application.h"
#include "../Renderer/Renderer.h"

namespace Hydro
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& name)
	{
		s_Instance = this;
		m_Window = Window::Create(WindowProps(name));

		Renderer::StartUp();
	}

	void Application::Run()
	{
	}
}
