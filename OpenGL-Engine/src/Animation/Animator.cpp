#include "Animator.h"



Animator::Animator()
{
}


Animator::~Animator()
{
}
void Animator::addClip()
{
}
AnimationClip Animator::findClip(std::string clipName)
{
	for (auto x : AnimationClips)
	{
		//change this to id or so cause clip name(string) is really slow
		if (x.first == clipName)
		{
			return x.second;
		}
	}
}
void Animator::playAnimation(AnimationClip clip)
{
	clip = findClip("");

}