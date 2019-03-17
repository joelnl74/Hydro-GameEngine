#include "CollisionSystem.h"
#include "../ECS_Engine.h"
bool CollisionSystem::Init()
{
	for (Component* component : ECS_Engine::GetInstance().m_ComponentManager->GetComponentsOfType<Collision>())
	{
		collisions.push_back(static_cast<Collision*>(component));
	}

	return true;
}

void CollisionSystem::Update()
{
	for (int i = 0; i < collisions.size(); i++)
	{
		for (int j = 0; j < collisions.size(); j++)
		{
			AABBCollision(*collisions[i], *collisions[j]);
		}
	}
}
void CollisionSystem::AABBCollision(Collision & coll1, Collision & coll2)
{
	if (coll1.getPosition().x < coll2.getPosition().x + coll2.getScale().x &&
		coll1.getPosition().x + coll1.getScale().x > coll2.getPosition().x &&
		coll1.getPosition().y < coll2.getPosition().y + coll2.getScale().y &&
		coll1.getPosition().y + coll1.getPosition().y > coll2.getPosition().y)
	{
		LOG_INFO("Collision Detected");
	}
}
