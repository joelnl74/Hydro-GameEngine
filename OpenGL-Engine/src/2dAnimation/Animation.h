#pragma once
#include "AnimationClip.h"
#include <map>
class Animation
{
public:
	Animation();
	~Animation();
	void addClip();
	void playAnimation();
private:
	std::map<std::string, AnimationClip> AnimationClips;
};

