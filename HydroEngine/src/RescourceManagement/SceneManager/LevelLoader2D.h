#pragma once
#include "../../Hydro.h"
#include <string>

class LevelLoader2D
{
public:
	bool loadScene(const std::string& inputFileName);
	bool saveScene(const std::string& inputFileName);
};

