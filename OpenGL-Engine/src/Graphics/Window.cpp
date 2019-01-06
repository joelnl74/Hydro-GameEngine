#include "Window.h"

 bool Window::m_keys[MAX_KEYS];
 bool Window::m_MouseButtons[MAX_BUTTONS];
//TODO CHANGE WINDOW TO WINDOWS API WINDOW!
Window::Window(const int &WINDOW_WIDTH, const int &WINDOW_HEIGHT, const char *WINDOW_TITLE)
{
	m_Title = WINDOW_TITLE;
	m_Width = WINDOW_WIDTH;
	m_Height = WINDOW_HEIGHT;
	if (!Init())
		glfwTerminate();
	glViewport(0, 0, m_Width, m_Height);

	for (int i = 0; i < MAX_KEYS; i++)
	{
		m_keys[i] = false;
	}

	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		m_MouseButtons[i] = false;
	}
}
Window::~Window()
{
	glfwTerminate();
}
bool Window::Init()
{
	if (!glfwInit())
		std::cout << "FAILED TO CREATE WINDOW" << std::endl;

	//TODO:Change to assert
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	if (!m_Window)
	{
		//TODO: Change to assert
		std::cout << "NO WINDOW WAS CREATED" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);
	glfwSetKeyCallback(m_Window, key_callback);
	glfwSetMouseButtonCallback(m_Window, mouse_callback);
	//NOTE change to 1 to turn v sync on
	glfwSwapInterval(1);
	if (glewInit() != GLEW_OK)
	{
		//TODO Change to Assert
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
bool Window::isKeyPressed(int keycode)
{
	//TODO LOG AS ERROR
	if (keycode >= MAX_KEYS)
		return false;

	return m_keys[keycode];
}
bool Window::isMouseButtonPressed(unsigned int button)
{
	if (button >= MAX_BUTTONS)
		return false;

		return m_keys[button];
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
		
	win->m_keys[key] = action != GLFW_RELEASE;
}
void mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);

	win->m_MouseButtons[button] = action != GLFW_RELEASE;
}
