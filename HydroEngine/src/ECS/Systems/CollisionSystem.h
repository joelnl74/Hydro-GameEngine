#pragma once
#include <unordered_map>

#include "../../Hydro.h"
#include "../System.h"
#include "../Components/Collision.h"
class CollisionSystem : public System
{
	virtual bool Init() override;
	virtual void Update() override;

	void AABBCollision(Collision& coll1, Collision& coll2);

private:
	std::unordered_map<int, Collision*> collisions;
};