#pragma once
#include "Components/Transform.h"
#include "Component.h"
#include <unordered_set>
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


	void AddComponent(Component *c)
	{
		components.emplace(c);
	}
private:
	std::unordered_set<Component*> components;
};

