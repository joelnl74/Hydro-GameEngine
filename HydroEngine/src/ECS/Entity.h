#pragma once
#include "Components/Transform.h"
#include "Component.h"
class Entity
{
public:
	unsigned int entityID;
	//Transform of a Entity
	Transform *transform = new Transform();

	Entity(Transform _transform)
	{
		transform = &_transform;
	}
	/*
	Create an empty entity
	PositionX, PositionY, PositionZ, ScaleX, ScaleY, ScaleZ
	*/
	Entity(float posX, float posY, float posZ, float scaleX, float scaleY, float scaleZ)
	{
		transform->position.x = posX;
		transform->position.y = posY;
		transform->position.z = posZ;

		transform->scale.x = scaleX;
		transform->scale.y = scaleY;
		transform->scale.z = scaleZ;
	}
	//Compare entities functies
	inline bool operator == (const Entity& rhs) const { return this->entityID == rhs.entityID; }
	inline bool operator != (const Entity& rhs) const { return this->entityID != rhs.entityID; }
	inline bool operator==(const Entity* rhs) const { return this->entityID == rhs->entityID; }
	inline bool operator!=(const Entity* rhs) const { return this->entityID != rhs->entityID; }

	//Add component to this specific entity
	void AddComponent(Component *component)
	{
		
	}
	//Remove component from this specific entity
	void RemoveComponent(Component* component)
	{

	}
	//Get component if exsist for this specific entity
	Component* GetComponent()
	{

	}
private:
};

