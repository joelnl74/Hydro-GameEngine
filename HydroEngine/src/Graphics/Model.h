#pragma once
#include "Mesh.h"

namespace Hydro
{
	class Model
	{
	public:
		Model(std::string path);
		void LoadModel(std::string path);
		void Draw(OpenGLShader &shader);
	private:
		std::vector<Mesh*> meshes;
	};
}
