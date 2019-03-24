#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <cstdio>
#include <string>
#include <vector>
#include "AudioSource.h"

class AudioManager
{
public:
	void Init();
	void CleanUp();
	void Update();
	void SetListener();
	int LoadAudioSound(const std::string &file);

	std::vector<int> buffers;
private:
	ALCdevice *m_device;
	ALCcontext  *m_context;
};