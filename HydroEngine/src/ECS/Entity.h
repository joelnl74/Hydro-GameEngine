#pragma once
#include "Components/Transform.h"
#include "Component.h"
#include <vector>
class Entity
{
public:
	int entityID;
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

	template<typename Component>
	Component* GetComponent() {
		Component* cmp = nullptr;
		
		for(int i = 0; i < components.size(); i++)
			if (Component* cmp = dynamic_cast<Component*>(components[i])) {
				return cmp;
			}
		return cmp;
	}
	void AddComponent(Component *c)
	{
		c->entity_ID = entityID;
		components.push_back(c);
	}
private:
	std::vector<Component*> components;
};

