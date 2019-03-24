#pragma once
#include <string>
struct AudioBuffer
{
	int channel;
	int samplerate;
	int bps;
	int size;
};

class WavFile
{
public:
	char* LoadWave(const std::string &file);
	char* StreamWave(const std::string &file);

	AudioBuffer m_audioBuffer;
private:
	int convertToInt(char* buffer, int len);
	bool isBigEndian();
};