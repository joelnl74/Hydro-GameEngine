#pragma once
#include "GameObject.h"

class Component
{
public:
	Component() {};
	~Component() {};

	virtual void Start() = 0;
	virtual void Update() = 0;
	
	GameObject *m_gameObject = nullptr;

private:
	bool active = true;
};