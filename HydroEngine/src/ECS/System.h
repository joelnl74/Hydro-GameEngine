#pragma once
class System
{
public:
	//Startup this system pure virtual every system must one way or another initilize itselfs
	virtual bool Init() = 0;
	//Update this system pure virtual every system must have a update statement
	virtual void Update() = 0;

	//Happens before update
	virtual void PreUpdate() {}
	//Happens after update
	virtual void LateUpdate() {}
};

