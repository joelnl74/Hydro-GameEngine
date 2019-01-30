#pragma once
#include "../Hydro.h"
class System
{
public:
	virtual ~System() {}
	//Startup this system pure virtual every system must one way or another initilize itselfs
	virtual bool Init() = 0;
	//Update this system pure virtual every system must have a update statement
	virtual void Update() = 0;

	//Happens before update
	virtual void PreUpdate() {}
	//Happens after update
	virtual void PostUpdate() {}

	bool active = true;
};

