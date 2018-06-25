#include "SceneManager.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>  
#include <vector>
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
	//check if we are at the last layer
	bool lastLayer = false;
	int couter = 0;
	//open stream to a file
	std::ofstream ofs;
	ofs.open(inputFileName);
	if (!ofs)
	{
		printf("ERROR OPENING FILE FROM DRIVE! FILE: %s", inputFileName);
		return false;
	}
	ofs.clear();

	//to create a array of spriteobjects
	ofs << "[";
	for (std::map<int, Layer*>::iterator it = l_manager->getManager()->begin(); it != l_manager->getManager()->end(); it++)
	{
		if (couter == l_manager->getManager()->size() - 1)
		{
			lastLayer = true;
		}
		for (auto x : it->second->returnSprites())
		{
			//create json object to write to json file
			json object = {
			{ "position",{ x->getPosition().x, x->getPosition().y} },
			{ "scale",{ x->getScale().x, x->getScale().y } },
			{ "uv",{ x->getUV().x * 4, x->getUV().y * 4 } },
			{ "solid", true }
			};

			ofs << object;

			if (it->second->returnSprites().back() == x && lastLayer)
			{
				printf("...");
			}
			else
			{
				ofs << ",";
			}
		}
		couter++;
	}
	//to close of the array of sprite objects
	ofs << "]";
	//close the stream
	ofs.close();
	return true;
}
