#pragma once
#include "../Graphics/RenderManager.h"
class SpriteEditor
{
public:
	SpriteEditor();
	~SpriteEditor();
	void M_SpriteEditor(RenderManager &gRenderManager, bool play, bool spriteEditor);
	void CreateSprite(RenderManager &gRenderManager);
	void setSelectedSprite(Sprite *sprite);

	bool spritePlacementMode = false;
private:
	bool solid = false;
	bool spriteCreator = false;
	bool isHovered = false;

	Sprite *selectedSprite = nullptr;

	float offset[2];
	float position[2];
	float scale[2];
	float uv[2];
	int layerID;
};

