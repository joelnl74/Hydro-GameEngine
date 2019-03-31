#pragma once
#include <typeinfo>
#include <unordered_map>

#include "Entity.h"

//Amout of components the vector should start with
#define COMPONENT_COUNT = 1024; 

class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	//TODO create new handle class[]
	//Add component to entity
	//template<class T>
	void AddComponent(Entity e, Component *component)
	{
		component->entity_ID = e.entityID;
		//Check if certain component entry exsist
		if(m_components.count(&typeid(*component)) > 0)
		{
			m_components.at(&typeid(*component)).push_back(component);
		}
		//Create new component entry
		else
		{
			//TODO Create new handle with this component type
			std::vector<Component*> newComponentList;
			m_components.emplace(&typeid(*component), newComponentList);
			m_components.at(&typeid(*component)).push_back(component);
		}
	}
	//Get Component from a certain entity
	template<class T>
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
	template<class T>
	void RemoveComponent(Entity e)
	{

	}
	//TODO see if we can return a vector of the derived class instead of the base class component
	//Return a vector of all the components of a certain type
	template<class T>
	std::vector<T*> &GetComponentsOfType()
	{
		std::vector<T*> *InheritedComponents = new std::vector<T*>();
		if (m_components.count(&typeid(T)) != 0)
		{
			for (Component *x : m_components.at(&typeid(T)))
			{
				T *derived = dynamic_cast<T*>(x);
				InheritedComponents->push_back(derived);
			}
			return *InheritedComponents;
		}
	}
private:
	//TODO Change from std::vector<Component*> to Handler which hold a refenrence to a vector containing a specific type of component!
	std::unordered_map<const type_info*, std::vector<Component*>> m_components;
};