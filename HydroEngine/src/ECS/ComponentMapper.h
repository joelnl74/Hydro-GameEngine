#pragma once
#include <unordered_map>
#include <typeinfo>
#include <typeindex>
#include <memory>

#include "Component.h"
class ComponentMapper
{
public:
	ComponentMapper();
	~ComponentMapper();

	//Look up the id that belongs to a certain componentType
	template<class T>
	int GetComponentID()
	{
		//TODO MAKE LOOKUP FASTER FOR FINDING COMPONENT ID
		//for (auto x : m_componentTypeNames)
		//{
		//	if (x.first == std::type_index(typeid(T)))
		//	{
		//		return m_componentTypeNames[std::type_index(typeid(T))];
		//	}
		//}
		//	m_componentTypeNames[std::type_index(typeid(T))] = m_amountOfComponentTypes;
		//	m_amountOfComponentTypes++;

		//	return m_componentTypeNames[std::type_index(typeid(T))];
	} 

private:
	std::unordered_map<const type_info*, int> m_componentTypeNames;
	int m_amountOfComponentTypes = 0;
};

