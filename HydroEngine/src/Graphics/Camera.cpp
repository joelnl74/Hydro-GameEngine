#include "Camera.h"
#include "../vendor/imgui/imgui.h"

namespace Hydro
{
	Camera::Camera(float width, float height, CameraMode mode)
	{
		m_width = width;
		m_height = height;
		m_cameraMode = mode;

		SetCameraMode(mode);
	}

	Camera::~Camera()
	{
	}

	void Camera::centerCamera(float x, float y)
	{
		//center the camera on a position
		m_position.x = x;
		m_position.y = y;
		m_Projection = glm::ortho(x - (m_width / 2), x + (m_width / 2), y - (m_height / 2), y + (m_height / 2), 0.0f, 100.0f);
	}

	void Camera::SetCameraMode(CameraMode mode)
	{
		//TEST 2D RENDERING
		if (mode == CameraMode::orthographic)
		{
			m_Projection = glm::ortho(0.0f, m_width, m_height, 0.0f, -1.0f, 1.0f);
		}
		//TEST 3D RENDERING
		if (mode == CameraMode::projection)
		{
			m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -3.0f));
			m_Projection = glm::perspective(glm::radians(90.0f), m_width / m_height, 0.1f, 100.0f);
		}
	}

	glm::vec2 Camera::returnWorldToCameraPosition()
	{
		glm::vec2 position;

		float xPos = m_width / 1024.0f;
		float yPos = m_height / 768.0f;

		position.x = xPos * ImGui::GetMousePos().x - (720 / 2) + m_position.x;
		position.y = m_height - yPos * ImGui::GetMousePos().y - (480 / 2) + m_position.y;

		return position;
	}
}
