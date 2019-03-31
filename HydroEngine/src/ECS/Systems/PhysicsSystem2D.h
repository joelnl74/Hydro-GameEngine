#pragma once
#include "../System.h"
class PhysicsSystem2D : public System
{
public:
	virtual bool Init() override;
	virtual void Update() override;
};

