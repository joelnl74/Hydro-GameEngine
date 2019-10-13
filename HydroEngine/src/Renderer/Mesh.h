#pragma once
#include <vector>
#include "../Platform/OpenGL/OpenGLTexture.h"
#include "../Platform/OpenGL/OpenGLShader.h"
#include "../Platform/OpenGL/OpenGLIndexBuffer.h"
#include "../Platform/OpenGL/OpenGLVertexBuffer.h"
#include "../Platform/OpenGL/OpenGLVertexBufferLayout.h"
#include "../Platform/OpenGL/OpenGLVertexArray.h"
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
		OpenGLVertexBuffer *vertexBuffer;
		OpenGLVerterArray *vertexArray;
		OpenGLVertexbufferLayout *layout;
		OpenGLIndexBuffer *indexBuffer;
		
		Assimp::Importer* m_Importer;
		const aiScene* m_Scene;

		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_Indices;

		/*  Functions    */
		void setupMesh();
		bool ProcessScene();
	};
}