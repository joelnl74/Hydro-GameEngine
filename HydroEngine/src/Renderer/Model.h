#pragma once
#include "Mesh.h"

namespace Hydro
{
	class Model
	{
	public:
		Model(std::string path);
		void LoadModel(std::string path);
		void Draw(Shader &shader);
	private:
		std::vector<Mesh*> meshes;
	};
}
