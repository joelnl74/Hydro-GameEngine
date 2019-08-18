#pragma once
#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"

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

		void centerCamera(float x, float y);
		void SetCameraMode(CameraMode _mode);

		glm::vec2 returnWorldToCameraPosition();

		inline glm::mat4 returnProjection() { return m_Projection; }
		inline const glm::vec2 returnCameraPosition() { return m_position; }
		inline const glm::vec2 returnCameraWindow() { return glm::vec2(m_width, m_height); }


	private:
		float m_width;
		float m_height;

		glm::mat4 m_Projection;
		glm::mat4 m_View;
		glm::vec3 m_position;

		CameraMode m_cameraMode;
	};
}
