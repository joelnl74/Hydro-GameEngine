#pragma once
#include <string>
#include <map>
#include "../Hydro.h"
#include "fmod_studio.hpp"
#include "fmod.hpp"

class AudioEngine
{
public:
	AudioEngine();
	~AudioEngine();
	bool LoadAudioFileFromSystem(const std::string filepath, std::string name, bool looped);
	bool PlaySound(std::string name);
private:
	FMOD::System    *system;
	FMOD::Channel   *channel = 0;
	
	std::map < std::string, FMOD::Sound *> audioClips;
};

