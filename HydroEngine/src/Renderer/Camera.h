#pragma once
#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

enum CameraMode
{
	orthographic,
	projection
};

namespace Hydro
{
	class Camera
	{
	public:
		Camera(float width, float height, CameraMode _mode);
		~Camera();

		inline glm::mat4 returnProjection() { return m_Projection; }
		inline glm::mat4 returnView() { return m_View; }
		inline const glm::vec3 ReturnCameraPosition() { return m_position; }
		inline const glm::vec3 ReturnCameraRotation() { return m_rotation; }
		inline const glm::vec2 ReturnCameraWindow() { return glm::vec2(m_width, m_height); }

		void SetCameraMode(CameraMode _mode);

	private:
		float m_width;
		float m_height;

		glm::mat4 m_Projection;
		glm::mat4 m_View;
		
		glm::vec3 m_position, m_rotation;

		CameraMode m_cameraMode;
	};
}
