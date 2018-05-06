#pragma once
#include <string.h>

#include "Graphics/Window.h"
class HydroEngine
{
public:
	HydroEngine(int height, int width);
	~HydroEngine();

	void StartUp();
	void ShutDown();
};

