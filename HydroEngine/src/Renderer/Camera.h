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

		inline glm::mat4 ReturnViewProjection() { return m_ViewProjectionMatrix; }
		inline glm::mat4 ReturnProjection() { return m_Projection; }
		inline glm::mat4 ReturnView() { return m_View; }
		inline const glm::vec3 ReturnCameraPosition() { return m_Position; }
		inline const float ReturnCameraRotation() { return m_Rotation; }
		inline const glm::vec2 ReturnCameraWindow() { return glm::vec2(m_width, m_height); }

		void SetCameraMode(CameraMode _mode);

	private:
		float m_width;
		float m_height;

		glm::mat4 m_Projection;
		glm::mat4 m_View;
		glm::mat4 m_ViewProjectionMatrix;
		
		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };

		float m_Rotation = 0.0f;

		CameraMode m_cameraMode;
	};
}
