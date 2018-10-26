#include "SceneManager.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>  
#include <vector>
#include "../../vendor/json/json.hpp"

using json = nlohmann::json;

//Loading a level from a json file into the engine/game
bool SceneManager::loadScene(const std::string& inputFileName, LayerManager* l_manager)
{
	//open a file from hard drive
	std::ifstream ifs(inputFileName);
	if (!ifs)
	{
		Logger::m_Instance->Error("ERROR OPENING FILE FROM DRIVE!, FILE NOT FOUND");
		return false;
	}
	json doc = doc.parse(ifs);
	ifs.close();
	for (json::iterator it = doc.begin(); it != doc.end(); ++it) {
		//find attributes key and value that are stored in the json file
		std::vector<int> pos = it->find("position").value().get<std::vector<int>>();
		std::vector<int> scale = it->find("scale").value().get<std::vector<int>>();
		std::vector<int> uv = it->find("uv").value().get<std::vector<int>>();
		bool solid = it->find("solid").value();
		int layer = it->find("layer").value();

		//Create a sprite with the information gained from the json file
		Sprite* sprite = new Sprite(scale[0], scale[1], pos[0], pos[1], solid);
		sprite->setIndex(4, 4);
		sprite->setTextureUV(uv[0], uv[1]);
		
		if (l_manager->getManager()->count(layer) == true)
		{
			l_manager->getLayer(layer)->SubmitSprite(*sprite);
		}
		else
		{
			l_manager->AddLayer(layer);
			l_manager->getLayer(layer)->SubmitSprite(*sprite);
		}

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
		Logger::m_Instance->Error("ERROR OPENING FILE FROM DRIVE!, FILE NOT FOUND");
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
		for (auto x : it->second->ReturnSprites())
		{
			//create json object to write to json file
			json object = {
			{ "position",{ x->getPosition().x, x->getPosition().y} },
			{ "scale",{ x->getScale().x, x->getScale().y } },
			{ "uv",{ x->getUV().x * 4, x->getUV().y * 4 } },
			{ "solid", true },
			{ "layer", it->first}
			};

			ofs << object;

			if (it->second->ReturnSprites().back() == x && lastLayer)
			{
				printf("reached last sprite in layer");
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
