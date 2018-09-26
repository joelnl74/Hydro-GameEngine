#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#include "../vendor/glm/common.hpp"
class OBJLoader
{
public:
	OBJLoader();
	~OBJLoader();
	bool LoadOBJ(const char* path, std::vector<glm::vec4> vertices, std::vector<glm::vec2> UV,std::vector<glm::vec3> normals);
};

