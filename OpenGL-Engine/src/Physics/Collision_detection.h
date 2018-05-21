#pragma once
#include <vector>
#include "../vendor/glm/vec2.hpp"
struct rect {
	glm::vec2 position;
	glm::vec2 scale;
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
	void addBoundingBox(glm::vec2 position, glm::vec2 scale);
	bool checkCollision(glm::vec2 position, glm::vec2 scale);
private: 
	std::vector<rect> collisionContainer;
};

