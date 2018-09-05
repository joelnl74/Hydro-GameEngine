#pragma once
#include <map>

#include "../Graphics/Texture.h"
class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	void addTexture(std::string name, Texture texture);
	void removeTexture(std::string name);
	Texture returnTexture(std::string);
private:
	std::map<std::string, Texture> *textures;
};

