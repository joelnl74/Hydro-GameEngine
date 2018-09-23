#include "Camera2D.h"
#include "../vendor/imgui/imgui.h"


Camera2D::Camera2D(float width, float height)
{
	m_width = width;
	m_height = height;
	orthographicCamera = glm::ortho(0.0f, width, 0.0f, height, 0.0f, 100.0f);
}
void Camera2D::centerCamera(float x, float y)
{
	//center the camera on a position
	cameraPosition.x = x;
	cameraPosition.y = y;
	orthographicCamera = glm::ortho(x - (m_width / 2), x + (m_width / 2), y - (m_height / 2), y + (m_height / 2), 0.0f, 100.0f);
}
glm::vec2 Camera2D::returnWorldToCameraPosition()
{
	float xPosition = m_width / 1024.0f;
	float yPosition = m_height / 768.0f;
	glm::vec2 position;

	position.x = xPosition * ImGui::GetMousePos().x - (720 / 2) + cameraPosition.x;
    position.y = m_height - yPosition * ImGui::GetMousePos().y - (480 / 2) + cameraPosition.y;

	return position;
}
Camera2D::~Camera2D()
{
}
void Camera2D::ChangeCameraMode()
{
}
