#pragma once

class AudioSource
{
public:
	void Init(float x, float y, float z, float gain, float pitch, int  &buffer);
	void playSource(int *buffer);
private:
	unsigned int sourceId;
	int source_State;
};