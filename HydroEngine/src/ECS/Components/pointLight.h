#pragma once
#include "Sprite.h"
class pointLight
{
public:
	pointLight();
	~pointLight();
	float intensity;
	float raidius;
private:
	glm::vec4 colors;
};

