#include "Win32Window.h"
#include "GL\glew.h"
#include "GL\wglew.h"
#include <stdio.h>;
namespace
{
	Win32Window * win32Window = NULL;
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (win32Window)
		return win32Window->MsgProc(hwnd, message, wParam, lParam);
	else
		return DefWindowProc(hwnd, message, wParam, lParam);
}

Win32Window::Win32Window(void)
{
}

Win32Window::Win32Window(HINSTANCE hinstance)
{
	m_AppInstance = hinstance;
	m_hAppWnd = NULL;
	m_hDevContext = NULL;
	m_hGLRendererContext = NULL;
	m_ClientWidth = 1024;
	m_ClientHeight = 768;
	m_AppTitle = "Hydro Engine";
	m_WindowStyle = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX;
	m_FPS = 0.0f;
	win32Window = this;
}
Win32Window::~Win32Window(void)
{
}
int Win32Window::Run()
{
	__int64 prevtime = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevtime);

	__int64 countPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER *)&countPerSec);
	float secondsPerCount = 1.0f / countPerSec;

	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			__int64 curTime = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
			float deltaTime = (curTime - prevtime) * secondsPerCount;
			Update(deltaTime);

			Render();

			CalculateFPS(deltaTime);
		
			prevtime = curTime;
		}
	}

	Shutdown();

	return static_cast<int>(msg.wParam);
}
bool Win32Window::InitWindow()
{
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.hInstance = m_AppInstance;
	wcex.lpfnWndProc = MainWndProc;
	wcex.hIcon = NULL;
	wcex.hCursor = NULL;
	wcex.hbrBackground = NULL;
	wcex.lpszClassName = "WIN32WINDOW";
	wcex.lpszMenuName = NULL;
	wcex.hIconSm = NULL;

	if (!RegisterClassEx(&wcex))
	{
		printf("ERROR REGISTERING WNDCLASSEX");
	}

	RECT r = { 0, 0, m_ClientWidth, m_ClientHeight };
	AdjustWindowRect(&r, m_WindowStyle, FALSE);
	int width = r.right - r.left;
	int height = r.bottom - r.top;
	int x = GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2;
	int y = GetSystemMetrics(SM_CXSCREEN) / 2 - height / 2;

	m_hAppWnd = CreateWindow("WIN32WINDOW", m_AppTitle, m_WindowStyle, x, y, width, height, NULL, NULL, m_AppInstance, NULL);
	if (!m_hAppWnd)
	{
		printf("COULD NOT CREATE WIN32 WINDOW");
	}
	ShowWindow(m_hAppWnd, SW_SHOW);

	return true;
}
bool Win32Window::Init()
{
	if (!InitWindow())
	{
		printf("FAILED TO CREATE WIN32 WINDOW");
		return false;
	}
	if (!InitGL())
	{
		printf("FAILED TO CREATE OPENGL CONTEXT");
		return false;
	}
	return true;
}
bool Win32Window::InitGL()
{
	m_hDevContext = GetDC(m_hAppWnd);

	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 8;
	int format = ChoosePixelFormat(m_hDevContext, &pfd);
	if (!SetPixelFormat(m_hDevContext, format, &pfd))
	{
		printf("ERROR CREATING PIXELFORMAT");
		return false;
	}

	m_hGLRendererContext = wglCreateContext(m_hDevContext);
	if (!wglMakeCurrent(m_hDevContext, m_hGLRendererContext))
	{
		printf("FAILED TO MAKE WGL CONTEXT");
		return false;
	}


	if (glewInit())
	{
		printf("FAILED TO INIT GLEW");
		return false;
	}


	return true;
}
void Win32Window::CalculateFPS(float dt)
{

}
void Win32Window::Shutdown()
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_hGLRendererContext);
	ReleaseDC(m_hAppWnd, m_hDevContext);
}
LRESULT Win32Window::MsgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	default:
	{
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	}
}