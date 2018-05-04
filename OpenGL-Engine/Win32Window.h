#pragma once
#include <Windows.h>
class Win32Window
{
public:
	//int WINAPI WinMain(HINSTANCE histance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	Win32Window(void);
	Win32Window(HINSTANCE hinstance);
	virtual ~Win32Window(void);

	int Run();
	virtual bool Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lparam);

protected:
	HWND		m_hAppWnd;
	HINSTANCE	m_AppInstance;
	HDC			m_hDevContext;
	HGLRC		m_hGLRendererContext;
	UINT		m_ClientWidth;
	UINT		m_ClientHeight;
	DWORD       m_WindowStyle;
	char*       m_AppTitle;
	float       m_FPS;

protected:
	bool InitWindow();
	bool InitGL();
	void CalculateFPS(float dt);
	void Shutdown();
};

