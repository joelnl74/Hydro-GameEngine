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

	void Camera::SetCameraMode(CameraMode mode)
	{
		if (mode == CameraMode::orthographic)
		{
			m_Projection = glm::ortho(0.0f, m_width, m_height, 0.0f, -1.0f, 1.0f);
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
