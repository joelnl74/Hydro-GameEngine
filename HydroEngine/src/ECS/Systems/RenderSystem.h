#pragma once
#include "../System.h"

#include "../../Graphics/spriteBatch.h"
class RenderSystem : public System
{
public:
	RenderSystem();
	~RenderSystem();

	virtual bool Init() override;
	virtual void Update() override;

	bool update = true;
private:
	spriteBatch *batch;
};

