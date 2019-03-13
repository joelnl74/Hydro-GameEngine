#pragma once
class Shape
{
public: 
	unsigned int VBO, VAO, IBO;
	Shader *_shader;
	virtual void Draw() = 0;
};
