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
bool SceneManager::saveScene(const std::string& inputFileName, LayerManager* l_manager)
{
	//foreach object i have to set the values


	std::ofstream ofs;
	ofs.open(inputFileName);
	ofs.clear();

	ofs << "[";
	for (int x = 0; x < 5; x++)
	{
		Sprite *sprite = new Sprite(32, 32, 32, 32, true);
		sprite->setTextureUV(1, 1);

		json object = {
		{ "position",{ sprite->getPosition().x + (x * 32), sprite->getPosition().y  } },
		{ "scale",{ sprite->getScale().x, sprite->getScale().y } },
		{ "uv",{0, 0 } },
		{ "solid", true },
		};
		ofs << object;
		if(x != 4)
		ofs << ",";
	}
	ofs << "]";
	ofs.close();
	
	return true;
}
