#include "Wave.h"



Wave::Wave()
{
	float vertices[] = {
		// positions   // texture coords
		0.5f,  0.0f, 0.5f,  1.0f, 1.0f,   // top right
		0.5f,  0.0f, -0.5f,  1.0f, 0.0f,   // bottom right
		-0.5f, 0.0f, -0.5f, 0.0f, 0.0f,   // bottom left
		-0.5f,  0.0f, 0.5f, 0.0f, 1.0f    // top left 
	};

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


Wave::~Wave()
{
}
