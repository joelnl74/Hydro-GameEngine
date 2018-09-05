#pragma once
#include <vector>

#include "../Component system/Component.h"
#include "../vendor/glm/vec2.hpp"
enum collisionType
{
	normal,
	trigger,
	event
};

struct collision : Component {
	glm::vec2 position;
	glm::vec2 scale;
	collisionType type;
	virtual void Update()
	{

	}
};
//TODO
//------------------------------------------------------------------------------------------------
//Narrow phase AABB collision detection[x]
//Narrow circle[]
//Broadphase collision detection[]
class Collision_detection
{
public:
	Collision_detection();
	~Collision_detection();
	void addCollision(collision col);
	bool checkCollision(glm::vec2 position, glm::vec2 scale);
private: 
	std::vector<collision> collisionContainer;
};

