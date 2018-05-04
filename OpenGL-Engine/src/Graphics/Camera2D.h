#pragma once
#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"
class Camera2D
{
public:
	Camera2D(float width, float height);
	~Camera2D();
	void centerCamera(float x, float y);
	glm::mat4 returnOrthographicCamera() { return orthographicCamera; }
	inline glm::vec2 returnCameraPosition() { return cameraPosition; }
private:
	glm::mat4 orthographicCamera;
	glm::vec2 cameraPosition;
	float m_width;
	float m_height;
};

