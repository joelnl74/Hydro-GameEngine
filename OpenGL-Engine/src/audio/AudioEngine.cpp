#include "AudioEngine.h"

AudioEngine::AudioEngine()
{
	FMOD::System_Create(&system);
	system->init(32, FMOD_INIT_NORMAL, 0);
}
AudioEngine::~AudioEngine()
{
	delete audioClip;
	delete system;
	delete channel1;
}
void AudioEngine::LoadAudioFileFromSystem(const std::string filepath)
{
	system->createSound(filepath.c_str(), FMOD_DEFAULT, 0, &audioClip);
	audioClip->setMode(FMOD_LOOP_NORMAL);
}
void AudioEngine::PlaySound()
{
	system->playSound(audioClip, 0, false, &channel1);
}