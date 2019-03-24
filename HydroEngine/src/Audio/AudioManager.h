#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <cstdio>

class AudioManager
{
public:
	void Init();
	void Update();

private:
	ALCdevice *m_device;
	ALCcontext  *m_context;
    int state;
};