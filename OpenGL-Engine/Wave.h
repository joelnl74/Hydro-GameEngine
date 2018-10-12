#pragma once
#include "src/Graphics/OpenGLDebugger/OpenglErrorHandler.h"
#include "src/Graphics/Texture.h"
class Wave
{
public:
	Wave();
	~Wave();
	void draw();
private:
	Texture *texture;
	Texture *texture2;
	unsigned int VBO, VAO;
};

