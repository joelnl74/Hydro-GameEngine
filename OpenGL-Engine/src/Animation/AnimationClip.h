#pragma once
#include "../Components/Sprite.h"
class AnimationClip
{
public:
	float interval;
	bool looping;
	int startingFrameX, startingFrameY;
	int endingFrameX, endingFrameY;
	int clipId;
};

