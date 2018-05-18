#pragma once

#include <string>
#include <vector>

#include "../Rescourcemanager.h"
#include "Sprite.h"
class Text
{
public:
	Text(const std::string &text, int positonX, int positionY);
	inline const std::vector<Sprite> returnVector() { return charlist; }
	void rendererText();
	~Text();
private:
	int offset = 0;
	int position_X, position_y;
	std::vector<Sprite> charlist;
	Rescourcemanager _rescourcemanager;
	void setChar(char &x);
};

