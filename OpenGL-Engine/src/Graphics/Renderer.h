#pragma once
#include "OpenGLDebugger\OpenglErrorHandler.h"

class Renderer
{
public:
	void Clear() const;
	Renderer();
	~Renderer();

private:
	unsigned int m_VAO;
};

