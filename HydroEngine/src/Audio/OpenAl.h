#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <cstdio>

class OpenAl
{
public:
	void Init();
	char* loadWAV(const char* fn, int& chan, int& samplerate, int& bps, int& size);
	int convertToInt(char* buffer, int len);
	bool isBigEndian();
private:
	ALCdevice *m_device;
	ALCcontext  *m_context;
	unsigned int source;
	unsigned int buffer;
    int state;
};