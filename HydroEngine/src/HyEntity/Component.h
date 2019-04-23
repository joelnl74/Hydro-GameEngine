#pragma once

class GameObject;

class Component
{
public:
	Component() {};
	~Component() {};

	virtual void Start() {};
	virtual void Update() {};

	GameObject *gameObject = nullptr;

private:
	bool active = true;
};