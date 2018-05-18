#include "Camera2D.h"



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

Camera2D::~Camera2D()
{
}
