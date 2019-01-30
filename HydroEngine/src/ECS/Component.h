#pragma once
class Component
{
public:
	//Need for storing type_id in ComponentManager, parent class needs a virtual method for this to work
	virtual ~Component() = default;

	//is the component active?
	bool active = true;	
	//Entity this component belongs to
	int entity_ID;
};
