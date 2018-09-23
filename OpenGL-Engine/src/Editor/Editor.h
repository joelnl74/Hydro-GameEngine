#pragma once
#include "EditorUI.h"
#include "../Graphics/Camera2D.h"
class Editor
{
public:
	Editor(GLFWwindow *win, Camera2D *camera);
	~Editor();
	EditorUI *ui;
	Camera2D *_camera;
	void UpdateInput();
};

