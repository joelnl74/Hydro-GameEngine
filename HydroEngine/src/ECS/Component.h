#pragma once
class Component 
{
public:
	int entity_ID;
	bool active = true;
	virtual void Update() = 0;
private:
};

