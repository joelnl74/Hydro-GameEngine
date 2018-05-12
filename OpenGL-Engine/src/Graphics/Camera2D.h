#pragma once
#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"
class Camera2D
{
public:
	Camera2D(float width, float height);
	~Camera2D();
	void centerCamera(float x, float y);
    inline glm::mat4 returnOrthographicCamera() { return orthographicCamera; }
	inline const glm::vec2 returnCameraPosition() { return cameraPosition; }
	inline const glm::vec2 returnCameraWindow() { return glm::vec2(m_width, m_height); }
private:
	glm::mat4 orthographicCamera;
	glm::vec2 cameraPosition;
	float m_width;
	float m_height;
};

