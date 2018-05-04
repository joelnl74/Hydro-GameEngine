#pragma once
#include "../vendor/glm/vec3.hpp" // glm::vec3
#include "../vendor/glm/vec4.hpp" // glm::vec4
#include "../vendor/glm/mat4x4.hpp" // glm::mat4
#include "../vendor/glm/gtc/matrix_transform.hpp" // glm::translate, glm::rotate, glm::scale, glm::perspective

class Camera
{
public:
	Camera();
	~Camera();
private:
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
};

