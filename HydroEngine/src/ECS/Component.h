#pragma once
#include <bitset>
class Component
{
public:
	virtual ~Component() = default;

	//is the component active?
	bool active = true;	
	//Entity this component belongs to
	int entity_ID;
	//The type of component this class is
	unsigned int ComponentType_ID;
};
