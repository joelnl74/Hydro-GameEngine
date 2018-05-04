#pragma once
#include <map>
#include "vendor/glm/vec2.hpp"
class Rescourcemanager
{
public:
	Rescourcemanager();
	~Rescourcemanager();
	glm::vec2 returnCharacter(char x) { return charLocations.at(x); }
private:
	std::map<char, glm::vec2> charLocations;
	void createFontSheet();
};

