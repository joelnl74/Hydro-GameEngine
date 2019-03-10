#include "Window.h"

Window::Window(const int &WINDOW_WIDTH, const int &WINDOW_HEIGHT, const char *WINDOW_TITLE)
{
	m_Title = WINDOW_TITLE;
	m_Width = WINDOW_WIDTH;
	m_Height = WINDOW_HEIGHT;
	if (!Init())
		glfwTerminate();
	glViewport(0, 0, m_Width, m_Height);
}
Window::~Window()
{
	glfwTerminate();
}
bool Window::Init()
{
	if (!glfwInit())
		std::cout << "FAILED TO CREATE WINDOW" << std::endl;

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	if (!m_Window)
	{
		//TODO: Change to assert
		std::cout << "NO WINDOW WAS CREATED" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);

	//NOTE change to 1 to turn v sync on
	glfwSwapInterval(1);
	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR INIT GLEW" << std::endl;
	}
	std::cout << glGetString(GL_VERSION) << std::endl;
	return true;
}
bool Window::closed() const
{
	return glfwWindowShouldClose(m_Window);
}
void Window::clear() const
{
	glClearColor(0, 0, 0, 0);
}
void Window::update() 
{
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}
