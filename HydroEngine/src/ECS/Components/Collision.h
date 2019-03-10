#pragma once
#include "../Component.h"
#include "../../vendor/glm/vec2.hpp"
enum collisionType
{
	normal,
	trigger,
	event
};
class Collision : public Component {
public:
	glm::vec2 position;
	glm::vec2 scale;
	collisionType type;
};
