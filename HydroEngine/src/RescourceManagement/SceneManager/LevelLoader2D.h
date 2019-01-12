#pragma once
#include "../../Hydro.h"
#include <string>
#include "../../Graphics/layering/LayerManager.h"
class LevelLoader2D
{
public:
	bool loadScene(const std::string& inputFileName, LayerManager* l_manager);
	bool saveScene(const std::string& inputFileName, LayerManager* l_manager);
};

