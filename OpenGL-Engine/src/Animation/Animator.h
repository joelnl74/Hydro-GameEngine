#pragma once
#include "AnimationClip.h"
#include <map>
class Animator
{
public:
	Animator();
	~Animator();
	void addClip();
	void playAnimation(AnimationClip clip);
	AnimationClip findClip(std::string clipName);
private:
	std::map<std::string, AnimationClip> AnimationClips;
	AnimationClip currentlyPlaing;
};

