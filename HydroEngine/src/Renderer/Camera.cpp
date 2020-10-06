#include "Camera.h"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

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

	void Camera::SetCameraMode(CameraMode mode)
	{
		if (mode == CameraMode::orthographic)
		{
			float min_x = m_width / 2;
			float min_y = m_height / 2;

			m_Projection = glm::ortho(-min_x, min_x, -min_y, min_y, -1.0f, 1.0f);
			glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) *
				glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

			m_View = glm::inverse(transform);
			m_ViewProjectionMatrix = m_Projection * m_View;
		}
		//TEST 3D RENDERING
		if (mode == CameraMode::projection)
		{
			m_View = glm::mat4(1);
			m_Projection = glm::mat4(1);

			m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -3.0f));
			m_Projection = glm::perspective(glm::radians(45.0f), m_width / m_height, 0.1f, 100.0f);
		}
	}
}
