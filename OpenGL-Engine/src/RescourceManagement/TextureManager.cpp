#include "TextureManager.h"

TextureManager::TextureManager()
{
	textures = new std::map<std::string, Texture>();
}
TextureManager::~TextureManager()
{
	delete textures;
}
void TextureManager::addTexture(std::string name, Texture texture)
{
	textures->emplace(name, texture);
}
void TextureManager::removeTexture(std::string name)
{
	textures->erase(textures->find(name));
}
Texture TextureManager::returnTexture(std::string name)
{
	return textures->find(name)->second;
}
