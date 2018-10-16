#pragma once
#include <vector>

#include "../ECS/Components/Collision.h"



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
	void addCollision(Collision col);
	bool checkCollision(glm::vec2 position, glm::vec2 scale);
private: 
	std::vector<Collision> collisionContainer;
};

