#pragma once
#include <vector>
#include <unordered_map>
//TODO make a handler to this class!
template <class Component_type>
class ComponentContainer
{
public:
	ComponentContainer() {}
	~ComponentContainer() {}

	template <class T>
	void CreateContainer()
	{
		std::vector<T> types;
		component_Types->emplace(component_Types->size() + 1, types);
	}
	template <class T>
	std::vector<Component_type> ReturnComponentContainerType(int id)
	{
		return component_Types->at(id);
	}

private:
	//Container of a certain component type
	std::unordered_map<int, std::vector<Component_type>> *component_Types;
};