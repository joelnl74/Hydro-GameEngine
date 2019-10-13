#include "Model.h"
#include <iostream>
#include "assimp/Importer.hpp"

namespace Hydro
{
	Model::Model(std::string path)
	{
		LoadModel(path);
	}

	void Model::LoadModel(std::string path)
	{
		Mesh *mesh = new Mesh(path);
		meshes.push_back(mesh);
	}
	void Model::Draw(Shader &shader)
	{
		for (int i = 0; i < meshes.size(); i++)
		{
			meshes[i]->Draw(shader);
		}
	}
}
