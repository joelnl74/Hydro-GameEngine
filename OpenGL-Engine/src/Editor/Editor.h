#pragma once
#include "EditorUI.h"
#include "../Graphics/Camera.h"
class Editor
{
public:
	Editor(GLFWwindow *win, Camera *camera);
	~Editor();
	EditorUI *ui;
	Camera *_camera;
	void UpdateInput();
};

