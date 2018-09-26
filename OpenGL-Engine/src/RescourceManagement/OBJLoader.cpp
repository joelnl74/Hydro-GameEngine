#include "OBJLoader.h"



OBJLoader::OBJLoader()
{
}


OBJLoader::~OBJLoader()
{
}
bool OBJLoader::LoadOBJ(const char* path, std::vector<glm::vec4> vertices, std::vector<glm::vec2> UV, std::vector<glm::vec3> normals)
{
	std::ifstream in(path);
	if (!in)
	{
		printf("Cannot open file location");
	}
	std::string line;

	while (std::getline(in, line))
	{
		//vertices
		if (line.substr(0, 2) == "v ")
		{
			
		}
		//Normals
		else if (line.substr(0, 2) == "f ")
		{
			
		}
		else if (line[0] == '#')
		{
			/* ignoring this line */
		}
		else
		{
			/* ignoring this line */
		}
	}
}