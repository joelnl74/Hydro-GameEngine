#pragma once
class Shape
{
public: 
	unsigned int VBO, VAO;
	Shader *_shader;
	virtual void Draw() = 0;
};
