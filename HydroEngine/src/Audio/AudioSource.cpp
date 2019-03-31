#include "AudioSource.h"
#include "AL/al.h"
void AudioSource::Init(float x, float y, float z, float gain, float pitch, int &buffer)
{
	alGenSources(1, &sourceId);
	alSourcef(sourceId, AL_GAIN, gain);
	alSourcef(sourceId, AL_PITCH, pitch);
	alSource3f(sourceId, AL_POSITION, x, y, z);

	alSourcei(sourceId, AL_BUFFER, buffer);
	alSourcePlay(sourceId);
	alSourcei(sourceId, AL_LOOPING, 1);
	alGetSourcei(sourceId, AL_SOURCE_STATE, &source_State);
}

void AudioSource::playSource(int *buffer)
{
	alGetSourcei(sourceId, AL_SOURCE_STATE, &source_State);

	if (source_State == AL_PLAYING)
	{
		alGetSourcei(sourceId, AL_SOURCE_STATE, &source_State);
	}
}

