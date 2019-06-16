#pragma once
#include <vorbis/codec.h>

#define OV_EXCLUDE_STATIC_CALLBACKS
#include <vorbis/vorbisfile.h>

#include <AL/al.h>
#include <AL/alc.h>
#include <cstdio>
#include <string>
#include <vector>
#include "AudioSource.h"

namespace Hydro
{
	class AudioManager
	{
	public:
		void Init();
		void CleanUp();
		void Update();
		void SetListener();
		int LoadAudioSound(char *fileName);
		void GetALCErrorString(int error);
		void LoadOGG(char *fileName, std::vector<char> &buffer, ALenum &format, ALsizei &freq);

		std::vector<int> buffers;
	private:
		int result;
		ALCdevice *m_device;
		ALCcontext  *m_context;
	};
}