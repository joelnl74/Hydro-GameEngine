#pragma once

#include <string>
#include <vector>

#include "../ECS/Components/Sprite.h"
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
	void setChar(char &x);
};

