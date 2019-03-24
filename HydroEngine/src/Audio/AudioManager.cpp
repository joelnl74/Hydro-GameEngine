#include "AudioManager.h"
#include "../Hydro.h"
#include "WavFile.h"

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
		return;
	}
}
void AudioManager::CleanUp()
{
	for (unsigned int buffer = 0; buffer < buffers.size(); buffer++)
	{
		alDeleteBuffers(1, &buffer);
	}
}
void AudioManager::Update()
{


}

void AudioManager::SetListener()
{
	alListener3f(AL_POSITION, 0, 0, 1);
	alListener3f(AL_VELOCITY, 0, 0,	0);
}

int AudioManager::LoadAudioSound(const std::string &file)
{
	unsigned int buffer = 0;
	unsigned int format = 0;

	alGenBuffers(1, &buffer);
	WavFile wavFile;

	char *data = wavFile.LoadWave(file);

	if (wavFile.m_audioBuffer.channel == 1)
	{
		if (wavFile.m_audioBuffer.bps == 8)
		{
			format = AL_FORMAT_MONO8;
		}
		else
		{
			format = AL_FORMAT_MONO16;
		}
	}
	else 
	{
		if (wavFile.m_audioBuffer.bps == 8)
		{
			format = AL_FORMAT_STEREO8;
		}
		else 
		{
		format = AL_FORMAT_STEREO16;
		}
	}

	alBufferData(buffer, format, data, wavFile.m_audioBuffer.size, wavFile.m_audioBuffer.samplerate);

	buffers.push_back(buffer);

	return buffer;
}
