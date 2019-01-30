#pragma once
#include <vector>

template<class T>
class ComponentContainer
{
public:
	ComponentContainer();
	~ComponentContainer();

private:
	std::vector<T> Compponents;
};