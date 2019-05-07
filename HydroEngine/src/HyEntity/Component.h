#pragma once
#include "GameObject.h"

class Component
{
public:
	Component(GameObject *gameObject) { m_gameObject = gameObject; };
	Component() {};
	~Component() {};

	virtual void Start() = 0;
	virtual void Update() = 0;
	
	GameObject *m_gameObject = nullptr;

private:
	bool active = true;
};