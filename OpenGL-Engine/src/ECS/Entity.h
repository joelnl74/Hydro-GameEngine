#pragma once
#include "Components/Transform.h"
#include "Component.h"

#include <vector>
class Entity
{
public:
	unsigned int entityID;
	//Transform of a Entity
	Transform *transform = new Transform();

	//Compare entities functies
	inline bool operator == (const Entity& rhs) const { return this->entityID == rhs.entityID; }
	inline bool operator != (const Entity& rhs) const { return this->entityID != rhs.entityID; }
	inline bool operator==(const Entity* rhs) const { return this->entityID == rhs->entityID; }
	inline bool operator!=(const Entity* rhs) const { return this->entityID != rhs->entityID; }

private:
};

