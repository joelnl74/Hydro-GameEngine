#include "Mesh.h"
#include "../Hydro.h"
#include <iostream>
#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"

namespace Hydro
{
	Mesh::Mesh()
	{
		// TODO should become reference of some sort to a texture
		setupMesh();
	}

	void Mesh::Draw(OpenGLShader &shader)
	{
		shader.Bind();

		glm::mat4 m_View = glm::mat4(1);
		glm::mat4 m_Projection = glm::mat4(1);

		m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -3.0f));
		m_Projection = glm::perspective(glm::radians(45.0f), float(800) / float(600), 0.1f, 100.0f);

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		float angle = 45.0f;
		modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));


		shader.SetMatrix4("projection",m_Projection);
		shader.SetMatrix4("view", m_View);
		shader.SetMatrix4("model", modelMatrix);

		vertexArray->Bind();

		glDrawArrays(GL_TRIANGLES, 0, 36);

		vertexArray->UnBind();


		shader.UnBind();
	}

	void Mesh::setupMesh()
	{
		layout = new OpenGLVertexbufferLayout();
		vertexBuffer = new OpenGLVertexBuffer(vertices, sizeof(vertices));
		layout->Push<float>(3);
		vertexArray = new OpenGLVerterArray();
		vertexArray->AddBuffer(*vertexBuffer, *layout);
	}
}

