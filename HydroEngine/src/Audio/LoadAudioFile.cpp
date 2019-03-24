#include "LoadAudioFile.h"
#include "../Hydro.h"

char* LoadAudioFile::LoadWave(const char * fn, AudioBuffer & audio)
{
	char buffer[4];
	std::ifstream in(fn, std::ios::binary);
	in.read(buffer, 4);
	if (strncmp(buffer, "RIFF", 4) != 0)
	{
		LOG_WARNING("This is not a valid wav file");

		return NULL;
	}
	in.read(buffer, 4);
	in.read(buffer, 4);      //WAVE
	in.read(buffer, 4);      //fmt
	in.read(buffer, 4);      //16
	in.read(buffer, 2);      //1
	in.read(buffer, 2);
	audio.channel = convertToInt(buffer, 2);
	in.read(buffer, 4);
	audio.samplerate = convertToInt(buffer, 4);
	in.read(buffer, 4);
	in.read(buffer, 2);
	in.read(buffer, 2);
	audio.bps = convertToInt(buffer, 2);
	in.read(buffer, 4);      //data
	in.read(buffer, 4);
	audio.size = convertToInt(buffer, 4);
	char* data = new char[audio.size];
	in.read(data, audio.size);
	return data;
}

char * LoadAudioFile::LoadOgg(const char * fn, AudioBuffer & audio)
{
	return nullptr;
}

char * LoadAudioFile::streamOgg(const char * fn, AudioBuffer & audio)
{
	return nullptr;
}

char * LoadAudioFile::streamWave(const char * fn, AudioBuffer & audio)
{
	return nullptr;
}

bool LoadAudioFile::isBigEndian()
{
	int a = 1;
	return !((char*)&a)[0];
}

int LoadAudioFile::convertToInt(char* buffer, int len)
{
	int a = 0;
	if (!isBigEndian())
		for (int i = 0; i<len; i++)
			((char*)&a)[i] = buffer[i];
	else
		for (int i = 0; i<len; i++)
			((char*)&a)[3 - i] = buffer[i];
	return a;
}
