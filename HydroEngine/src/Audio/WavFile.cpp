#include "WavFile.h"
#include "../Hydro.h"

char* WavFile::LoadWave(const std::string &file)
{
	char buffer[4];
	std::ifstream in(file, std::ios::binary);
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
	m_audioBuffer.channel = convertToInt(buffer, 2);
	in.read(buffer, 4);
	m_audioBuffer.samplerate = convertToInt(buffer, 4);
	in.read(buffer, 4);
	in.read(buffer, 2);
	in.read(buffer, 2);
	m_audioBuffer.bps = convertToInt(buffer, 2);
	in.read(buffer, 4);      //data
	in.read(buffer, 4);
	m_audioBuffer.size = convertToInt(buffer, 4);
	char* data = new char[m_audioBuffer.size];
	in.read(data, m_audioBuffer.size);

	return data;
}

char * WavFile::StreamWave(const std::string &file)
{
	return nullptr;
}

bool WavFile::isBigEndian()
{
	int a = 1;
	return !((char*)&a)[0];
}

int WavFile::convertToInt(char* buffer, int len)
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
