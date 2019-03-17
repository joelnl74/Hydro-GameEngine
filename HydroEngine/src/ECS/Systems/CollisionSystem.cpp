#include "CollisionSystem.h"
#include "../ECS_Engine.h"
bool CollisionSystem::Init()
{
	std::vector<Component*> &collision = ECS_Engine::GetInstance().m_ComponentManager->GetComponentsOfType<Collision>();

	return true;
}

void CollisionSystem::Update()
{
}
void CollisionSystem::AABBCollision(Collision & coll1, Collision & coll2)
{
	if (coll1.position.x < coll2.position.x + coll2.scale.x &&
		coll1.position.x + coll1.scale.x > coll2.position.x &&
		coll1.position.y < coll2.position.y + coll2.scale.y &&
		coll1.position.y + coll1.scale.y > coll2.position.y)
	{
		LOG_INFO("Collision Detected");
	}
}
