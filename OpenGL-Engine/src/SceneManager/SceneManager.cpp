#include "SceneManager.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>  
#include <vector>
#include "../Graphics/Sprite.h"
#include "../vendor/json/json.hpp"

using json = nlohmann::json;
SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}
//Loading a level file into the engine
bool SceneManager::loadScene(const std::string& inputFileName, LayerManager* l_manager)
{
	//open a file from hard drive
	std::ifstream ifs(inputFileName);
	if (!ifs)
	{
		printf("ERROR OPENING FILE FROM DRIVE! FILE: %s", inputFileName);
		return false;
	}
	json doc = doc.parse(ifs);
	ifs.close();
	for (json::iterator it = doc.begin(); it != doc.end(); ++it) {
		std::vector<int> pos = it->find("position").value().get<std::vector<int>>();
		std::vector<int> scale = it->find("scale").value().get<std::vector<int>>();
		std::vector<int> uv = it->find("uv").value().get<std::vector<int>>();
		bool solid = it->find("solid").value();

		Sprite* sprite = new Sprite(scale[0], scale[1], pos[0], pos[1], solid);
		sprite->setIndex(4, 4);
		sprite->setTextureUV(uv[0], uv[1]);

		l_manager->getLayer(0)->submitSprite(*sprite);
	}
	return true;
}
//Save a level to a json file
void SceneManager::saveScene(const std::string& inputFileName)
{
	//each object in levelmanager create a json object
	json object;
	//foreach object i have to set the values

	//push them on a vector of jsonobjects

	//write everything to a json file
}
