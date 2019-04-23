#pragma onc
#include "../vendor/glm/common.hpp"
class Transform
{
public:
	//Position of the object its attached to
	glm::vec3 position;
	//Scale of the object its attached to
	glm::vec3 scale;
	//Rotation of the object its attached to
	glm::vec3 rotation;
};