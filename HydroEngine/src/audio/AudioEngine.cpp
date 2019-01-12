#include "AudioEngine.h"
#include <cstdio>
AudioEngine::AudioEngine()
{
	FMOD::System_Create(&system);
	system->init(32, FMOD_INIT_NORMAL, 0);
}
AudioEngine::~AudioEngine()
{
	if (audioClips.size() > 0)
	{
		for (auto x : audioClips)
		{
			hdel x.second;
		}
		audioClips.clear();
	}
	if(channel != NULL)
	hdel channel;
	system->close();
}
bool AudioEngine::LoadAudioFileFromSystem(const std::string filepath,std::string name, bool looped)
{
	FMOD::Sound *audioClip;
	system->createSound(filepath.c_str(), FMOD_DEFAULT, 0, &audioClip);
	if (looped)
	{
		audioClip->setMode(FMOD_LOOP_NORMAL);
	}
	audioClips.emplace(name, audioClip);
	return true;
}
bool AudioEngine::PlaySound(std::string name)
{
	for (auto x : audioClips)
	{
		if (x.first == name)
		{
			system->playSound(audioClips.at(name), 0, false, &channel);
			system->update();
			return true;
		}
	}
	LOG_INFO("ERROR:AUDIOCLIP NOT FOUND, CHECK IF YOU HAVE ADDED THE AUDIO CLIP FIRST");
	return false;
}