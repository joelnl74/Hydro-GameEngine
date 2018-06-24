#include "Rescourcemanager.h"


//TODO make class singleton
Rescourcemanager::Rescourcemanager()
{
	createFontSheet();
}


Rescourcemanager::~Rescourcemanager()
{
}
void Rescourcemanager::createFontSheet()
{
	charLocations.emplace(' ', glm::vec2(0, 0));
	charLocations.emplace('@', glm::vec2(0, 2));
	charLocations.emplace('A', glm::vec2(1, 2));
	charLocations.emplace('B', glm::vec2(2, 2));
	charLocations.emplace('C', glm::vec2(3, 2));
	charLocations.emplace('D', glm::vec2(4, 2));
	charLocations.emplace('E', glm::vec2(5, 2));
	charLocations.emplace('F', glm::vec2(6, 2));
	charLocations.emplace('G', glm::vec2(7, 2));
	charLocations.emplace('H', glm::vec2(8, 2));
	charLocations.emplace('I', glm::vec2(9, 2));
	charLocations.emplace('J', glm::vec2(10, 2));
	charLocations.emplace('K', glm::vec2(11, 2));
	charLocations.emplace('L', glm::vec2(12, 2));
	charLocations.emplace('M', glm::vec2(13, 2));
	charLocations.emplace('N', glm::vec2(14, 2));
	charLocations.emplace('O', glm::vec2(15, 2));
	charLocations.emplace('P', glm::vec2(0, 3));
	charLocations.emplace('Q', glm::vec2(1, 3));
	charLocations.emplace('R', glm::vec2(2, 3));
	charLocations.emplace('S', glm::vec2(3, 3));
	charLocations.emplace('T', glm::vec2(4, 3));
	charLocations.emplace('U', glm::vec2(5, 3));
	charLocations.emplace('V', glm::vec2(6, 3));
	charLocations.emplace('W', glm::vec2(7, 3));
	charLocations.emplace('X', glm::vec2(8, 3));
	charLocations.emplace('Y', glm::vec2(9, 3));
	charLocations.emplace('Z', glm::vec2(10, 3));

}
