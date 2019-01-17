#pragma once
class Component 
{
protected:
	int entity_ID;
	int component_ID;
public:
	virtual void Update() = 0;
private:
};

