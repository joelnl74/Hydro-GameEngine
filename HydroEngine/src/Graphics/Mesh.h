#pragma once
#include <vector>
#include "../Platform/OpenGL/OpenGLTexture.h"
#include "../Platform/OpenGL/OpenGLShader.h"
#include "../Platform/OpenGL/OpenGLIndexBuffer.h"
#include "../Platform/OpenGL/OpenGLVertexBuffer.h"
#include "../Platform/OpenGL/OpenGLVertexBufferLayout.h"
#include "../Platform/OpenGL/OpenGLVertexArray.h"
#include "../vendor/glm/glm.hpp"

// Mesh class contains data for rendering a mesh onto the screen.
// Currently only supports OpenGL
// TODO Makes this more friendly for different API.

namespace Hydro
{
	struct Vertex 
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};
	class Mesh
	{
	public:
		/*  Mesh Data  */
		/*  Functions  */
		Mesh();
		void Draw(OpenGLShader &shader);
	private:
		OpenGLVertexBuffer *vertexBuffer;
		OpenGLVerterArray *vertexArray;
		OpenGLVertexbufferLayout *layout;

		float vertices[108] = {
			-0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f,  0.5f, -0.5f,
			 0.5f,  0.5f, -0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,

			-0.5f, -0.5f,  0.5f,
			 0.5f, -0.5f,  0.5f,
			 0.5f,  0.5f,  0.5f,
			 0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,
			-0.5f, -0.5f,  0.5f,

			-0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,

			 0.5f,  0.5f,  0.5f,
			 0.5f,  0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f,  0.5f,
			 0.5f,  0.5f,  0.5f,

			-0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f, -0.5f,
			 0.5f, -0.5f,  0.5f,
			 0.5f, -0.5f,  0.5f,
			-0.5f, -0.5f,  0.5f,
			-0.5f, -0.5f, -0.5f,

			-0.5f,  0.5f, -0.5f,
			 0.5f,  0.5f, -0.5f,
			 0.5f,  0.5f,  0.5f,
			 0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f, -0.5f
			};

		/*  Functions    */
		void setupMesh();
	};
}