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
		inline glm::mat4 returnProjection() { return cameraProjection; }
		inline const glm::vec2 returnCameraPosition() { return cameraPosition; }
		inline const glm::vec2 returnCameraWindow() { return glm::vec2(m_width, m_height); }
		glm::vec2 returnWorldToCameraPosition();
		void ChangeCameraMode();

		//Test Code
		glm::mat4 cameraProjection;
		glm::mat4 view;
		glm::vec3 cameraPosition;
		CameraMode _cameraMode;
	private:
		float m_width;
		float m_height;
	};
}
