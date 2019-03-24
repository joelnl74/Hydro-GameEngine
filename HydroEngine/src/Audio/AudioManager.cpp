#include "AudioManager.h"
#include "../Hydro.h"

void AudioManager::Init()
{
	m_device = alcOpenDevice(0);

	if (m_device) {
		m_context = alcCreateContext(m_device, 0);
		alcMakeContextCurrent(m_context);
	}

	ALenum error = alGetError();

	if ((error = alGetError()) != AL_NO_ERROR)
	{
		//TODO log
		//DisplayALError("alGenBuffers :", error);
		return;
	}
	int channel, sampleRate, bps, size;
	//char* data = loadWAV("Resources/sounds/348275__bigmanjoe__fantasy-orchestra.wav", channel, sampleRate, bps, size);

	unsigned int bufferid, format;
	alGenBuffers(1, &bufferid);

	//if (channel == 1)
	//{
	//	if (bps == 8)
	//	{
	//		format = AL_FORMAT_MONO8;
	//	}
	//	else {
	//		format = AL_FORMAT_MONO16;
	//	}
	//}
	//else {
	//	if (bps == 8)
	//	{
	//		format = AL_FORMAT_STEREO8;
	//	}
	//	else {
	//		format = AL_FORMAT_STEREO16;
	//	}
	//}

	//alBufferData(bufferid, format, data, size, sampleRate);
	unsigned int sourceid;
	alGenSources(1, &sourceid);
	alSourcei(sourceid, AL_BUFFER, bufferid);
	alSourcePlay(sourceid);

	// Check foreach audio file in buffer if state is playing and play the audio file in the main loop!
	do {
		alGetSourcei(sourceid, AL_SOURCE_STATE, &state);
	} while (state == AL_PLAYING);

}
void AudioManager::Update()
{


}
