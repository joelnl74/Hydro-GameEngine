#pragma once
#include <string>
#include <map>

#include "fmod_studio.hpp"
#include "fmod.hpp"

class AudioEngine
{
public:
	AudioEngine();
	~AudioEngine();
	void LoadAudioFileFromSystem(const std::string filepath);
	void PlaySound();
private:
	FMOD::System     *system;
	FMOD::Sound     *audioClip;
	FMOD::Channel    *channel1 = 0;
};

