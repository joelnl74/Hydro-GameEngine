#pragma once
#include <vector>

#include "Component.h"
#include "Transform.h"

namespace Hydro
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		// Add Component
		void AddComponent(Component *component)
		{
			// Push back object
			component->GameObjectId = Id;
			component->transform = transform;
			components.push_back(component);
		}

		// Has component
		template<typename ComponentType>
		bool HasComponent() {

			for (unsigned int i = 0; i < components.size(); i++) {
				if (ComponentType* cmp = dynamic_cast<ComponentType*>(components[i])) {
					return true;
				}
			}
			return false;
		}

		// Get component
		template<typename ComponentType>
		ComponentType* GetComponent() {
			for (unsigned int i = 0; i < components.size(); i++) {
				if (ComponentType* cmp = dynamic_cast<ComponentType*>(components[i])) {
					return cmp;
				}
			}
			return NULL;
		}

		void Update()
		{
			for (auto x : components)
			{
				x->Update();
			}
		}
	public:
		unsigned int Id;
		Transform *transform;

	private:
		std::vector<Component*> components;
	};
}



