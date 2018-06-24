#pragma once
#include <string>
#include "../Graphics/layering/LayerManager.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	bool loadScene(const std::string& inputFileName, LayerManager* l_manager);
	void saveScene(const std::string& inputFileName);
};

