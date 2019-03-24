#pragma once

struct AudioBuffer
{
	int channel;
	int samplerate;
	int bps;
	int size;
};

class LoadAudioFile
{
public:
	char* LoadWave(const char* fn, AudioBuffer &audio);
	char* LoadOgg(const char* fn, AudioBuffer &audio);
	char* streamOgg(const char *fn, AudioBuffer &audio);
	char* streamWave(const char *fn, AudioBuffer &audio);

private:
	int convertToInt(char* buffer, int len);
	bool isBigEndian();
};