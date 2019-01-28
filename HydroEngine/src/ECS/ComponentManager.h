#pragma once
#include <vector>
#include <typeinfo>
#include "EntityManager.h"

class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	template<class T>
	void AddComponent(Entity e, Component *component)
	{
		//TODO check if this step is needed
		Entity entity = EntityManager::GetInstance().GetEntity(e);
		if (m_components.count(&typeid(*component)) > 0)
		{
		    //type = m_components.count(m_Mapper.GetComponentID<T>());
			m_components.at(&typeid(*component)).push_back(component);
		}
		else
		{
		    //type = m_components.count(m_Mapper.GetComponentID<T>());
			std::vector<Component*> newComponentList;
			m_components.emplace(&typeid(*component), newComponentList);
			m_components.at(&typeid(*component)).push_back(component);
		}
	}
	//Get Component from a certain entity
	template<typename Component>
	void GetComponent(Entity e)
	{

	}
	//Remove a component from an entity
	template<typename Component>
	void RemoveComponent(Entity e)
	{

	}
	//Return a vector of all the components of a certain type
	template<typename Component>
	std::vector<Component*> &GetComponentsOfType(int ComponentTypeID)
	{
		if (m_components.count(m_Mapper.GetComponentID<T>()) > 0)
		{
			int type = m_components.count(m_Mapper.GetComponentID<T>());
			return m_components.at(type);
		}
		else
		{
			return nullptr;
		}
	}
	
private:
	//TODO make the lookup generic
	std::unordered_map<const type_info*, std::vector<Component*>> m_components;
	//ComponentMapper m_Mapper;
};