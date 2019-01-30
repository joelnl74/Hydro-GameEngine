#pragma once
#include <vector>
#include <typeinfo>
#include <unordered_map>
#include "Entity.h"
class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	//Add component to entity
	void AddComponent(Entity e, Component *component)
	{
		if (m_components.count(&typeid(*component)) > 0)
		{
			component->entity_ID = e.entityID;
			m_components.at(&typeid(*component)).push_back(component);
		}
		else
		{
			component->entity_ID = e.entityID;
			std::vector<Component*> newComponentList;
			m_components.emplace(&typeid(*component), newComponentList);
			m_components.at(&typeid(*component)).push_back(component);
		}
	}
	//Get Component from a certain entity
	template<typename T>
	T &GetComponent(Entity e)
	{
		if (m_components.count(&typeid(T)) != 0)
		{
			for(Component * component : m_components.at(&typeid(T)))
			{
				if (component->entity_ID == e.entityID)
				{
					return  *dynamic_cast<T*>(component);
				}
			}
		}
	}
	//Remove a component from an entity
	template<typename Component>
	void RemoveComponent(Entity e)
	{

	}
	//TODO see if we can return a vector of the derived class instead of the base class component
	//Return a vector of all the components of a certain type
	template<typename T>
	std::vector<Component*> &GetComponentsOfType()
	{
		if (m_components.count(&typeid(T)) != 0)
		{
			return  m_components.at(&typeid(T));
		}
	}
	
private:
	//TODO Check if we need to change the vector to a template type T
	std::unordered_map<const type_info*, std::vector<Component*>> m_components;
};