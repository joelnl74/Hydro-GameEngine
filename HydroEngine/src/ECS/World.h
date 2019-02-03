#pragma once
#include "Systems/RenderSystem.h"
#include "ECS_Engine.h"
class World
{
public:
	World();
	~World();

private:
	RenderSystem *rendersystem;
};

