#include "AudioManager.h"
#include "../Hydro.h"
#include "AL/alc.h"

#define BUFFER_SIZE     32768       // 32 KB buffers

namespace Hydro
{
	void AudioManager::Init()
	{
		LOG_INFO("Initializing Audio engine!");

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

		LOG_INFO("Succes initializing Audio engine!");
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
		alListener3f(AL_VELOCITY, 0, 0, 0);
	}

	void AudioManager::LoadOGG(char *fileName, std::vector<char> &buffer, ALenum &format, ALsizei &freq)
	{
		int endian = 0;                         // 0 for Little-Endian, 1 for Big-Endian
		int bitStream;
		long bytes;
		char array[BUFFER_SIZE];                // Local fixed size array
		FILE *stream;
		errno_t err;


		// Open for binary reading
		err = fopen_s(&stream, fileName, "rb");

		if (stream == NULL)
		{
			exit(-1);
		}
		// end if

		vorbis_info *pInfo;
		OggVorbis_File oggFile;

		// Try opening the given file
		if (ov_open(stream, &oggFile, NULL, 0) != 0)
		{
			exit(-1);
		}

		// Get some information about the OGG file
		pInfo = ov_info(&oggFile, -1);

		// Check the number of channels... always use 16-bit samples
		if (pInfo->channels == 1)
			format = AL_FORMAT_MONO16;
		else
			format = AL_FORMAT_STEREO16;
		// end if

		// The frequency of the sampling rate
		freq = pInfo->rate;

		// Keep reading until all is read
		do
		{
			// Read up to a buffer's worth of decoded sound data
			bytes = ov_read(&oggFile, array, BUFFER_SIZE, endian, 2, 1, &bitStream);

			if (bytes < 0)
			{
				ov_clear(&oggFile);
				exit(-1);
			}
			// end if

			// Append to end of buffer
			buffer.insert(buffer.end(), array, array + bytes);
		} while (bytes > 0);

		// Clean up!
		ov_clear(&oggFile);
	}
	// end of LoadOGG

	int AudioManager::LoadAudioSound(char *fileName)
	{
		ALint state;                            // The state of the sound source
		ALuint bufferID;                        // The OpenAL sound buffer ID
		ALuint sourceID;                        // The OpenAL sound source
		ALenum format;                          // The sound data format
		ALsizei freq;                           // The frequency of the sound data
		std::vector<char> bufferData;           // The sound buffer data from file

		// Make sure there is a file name

		// end if

		// Create sound buffer and source
		alGenBuffers(1, &bufferID);

		// Load the OGG file into memory
		LoadOGG(fileName, bufferData, format, freq);

		// Upload sound data to buffer
		alBufferData(bufferID, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq);

		return bufferID;
	}

	void AudioManager::GetALCErrorString(int err) {
		switch (err) {
		case ALC_NO_ERROR:
			LOG_ERROR("AL_NO_ERROR");
		case ALC_INVALID_DEVICE:
			LOG_ERROR("ALC_INVALID_DEVICE");
		case ALC_INVALID_CONTEXT:
			LOG_ERROR("ALC_INVALID_CONTEXT");
		case ALC_INVALID_ENUM:
			LOG_ERROR("ALC_INVALID_ENUM");
		case ALC_INVALID_VALUE:
			LOG_ERROR("ALC_INVALID_VALUE");
		case ALC_OUT_OF_MEMORY:
			LOG_ERROR("ALC_OUT_OF_MEMORY");
		default:
			LOG_ERROR("SOME ERROR OCCURED!");
		}
	}
}