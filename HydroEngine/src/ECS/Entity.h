#pragma once
#include "Components/Transform.h"
#include "Component.h"
class Entity
{
public:
	unsigned int entityID;
	//Transform of a Entity
	Transform *transform = new Transform();

	Entity()
	{

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
private:
};

