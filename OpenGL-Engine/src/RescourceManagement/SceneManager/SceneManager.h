#pragma once
#include <string>
#include "../../Graphics/layering/LayerManager.h"
class SceneManager
{
public:
	bool loadScene(const std::string& inputFileName, LayerManager* l_manager);
	bool saveScene(const std::string& inputFileName, LayerManager* l_manager);
};

