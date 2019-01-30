#pragma once
#include "../System.h"

#include "../../Graphics/layering/Layer.h"
class RenderSystem : public System
{
public:
	RenderSystem();
	~RenderSystem();

	bool Init();
	void Update();
private:
	Layer *layer;
};

