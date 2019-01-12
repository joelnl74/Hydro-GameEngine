#include "Text.h"



Text::Text(const std::string &text, int positionX, int positionY)
{
	position_X = positionX;
	position_y = positionY;
	for (char x : text)
	{
		offset += 16;
		setChar(x);
	}
}
Text::~Text()
{
}
void Text::rendererText()
{

}
void Text::setChar(char &x)
{
	Sprite sprite(24, 24, position_X + offset, position_y);
	//sprite.setTextureUV(_rescourcemanager.returnCharacter(x).x, _rescourcemanager.returnCharacter(x).y);
	charlist.push_back(sprite);
}
