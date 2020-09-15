#pragma once
#include <vector>
#include "../Platform/OpenGL/OpenGLTexture.h"
#include "../Platform/OpenGL/OpenGLShader.h"
#include "buffer/IndexBuffer.h"
#include "buffer/VertexBuffer.h"
#include "buffer/BufferLayout.h"
#include "buffer/VertexArray.h"
#include "../vendor/glm/glm.hpp"

#include "assimp/Importer.hpp"
// Mesh class contains data for rendering a mesh onto the screen.
// Currently only supports OpenGL
// TODO Makes this more friendly for different API.

namespace Hydro
{
	struct Vertex 
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec3 Tangent;
		glm::vec3 Binormal;
		glm::vec2 TexCoords;
	};

	class Mesh
	{
	public:
		/*  Mesh Data  */
		/*  Functions  */
		Mesh(std::string &filePath);
		void Draw(Shader &shader);
	private:
		VertexBuffer *vertexBuffer;
		VertexArray *vertexArray;
		BufferLayout *layout;
		IndexBuffer *indexBuffer;
		
		Assimp::Importer* m_Importer;
		const aiScene* m_Scene;

		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_Indices;
	};
}