#include "Renderer.h"

#include <iostream>


Renderer::Renderer()
{

}


Renderer::~Renderer()
{
}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

