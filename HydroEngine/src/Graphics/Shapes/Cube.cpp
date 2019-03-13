#include "Cube.h"
#include "../../vendor/glm/gtc/matrix_transform.hpp"
#include  "GLFW/glfw3.h"

Cube::Cube(Shader *shader)
{
	_shader = shader;
	texture = hnew Texture("Resources/textures/seamless_brick-512x512.png");
	texture2 = hnew Texture("Resources/textures/Hydro_Engine.png");
	
	shader->Bind();
	shader->setUniform1i("u_Texture", 0);
	shader->setUniform1i("u_Texture1", 1);
	shader->UnBind();

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

}
Cube::~Cube()
{
	delete _shader;
}

void Cube::Draw()
{
	// calculate the model matrix for each object and pass it to shader before drawing
	_shader->Bind();
	texture->bind(0);
	texture2->bind(1);
	glm::mat4 model;
	_shader->SetMatrix4("model", model);
	_shader->setUniform1f("deltaTime", glfwGetTime());
	glDrawArrays(GL_TRIANGLES, 0, 36);
	texture->unBind();
	texture2->unBind();
	_shader->UnBind();
}
