#pragma once
#include "../Graphics/Texture.h"
class AnimationClip
{
public:
	AnimationClip();
	~AnimationClip();

	float interval;
	bool looping;
	int startingFrameX, startingFrameY;
	int endingFrameX, endingFrameY;

	Texture texture;

};

