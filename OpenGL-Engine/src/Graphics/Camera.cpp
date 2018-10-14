#include "Camera.h"
#include "../vendor/imgui/imgui.h"


Camera::Camera(float width, float height)
{
	m_width = width;
	m_height = height;

	//cameraProjection = glm::ortho(0.0f, width, 0.0f, height, 0.0f, 100.0f);

	//code for vincent
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	cameraProjection = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
}
void Camera::centerCamera(float x, float y)
{
	//center the camera on a position
	cameraPosition.x = x;
	cameraPosition.y = y;
	cameraProjection = glm::ortho(x - (m_width / 2), x + (m_width / 2), y - (m_height / 2), y + (m_height / 2), 0.0f, 100.0f);
}
glm::vec2 Camera::returnWorldToCameraPosition()
{
	float xPosition = m_width / 1024.0f;
	float yPosition = m_height / 768.0f;
	glm::vec2 position;

	position.x = xPosition * ImGui::GetMousePos().x - (720 / 2) + cameraPosition.x;
    position.y = m_height - yPosition * ImGui::GetMousePos().y - (480 / 2) + cameraPosition.y;

	return position;
}
Camera::~Camera()
{
}
void Camera::ChangeCameraMode()
{
}
