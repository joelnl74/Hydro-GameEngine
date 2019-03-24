#pragma once
class AudioSource
{
public:
	void playSource();
	void playLoopedSource();
	void UpdateSource();
private:
	int sourceId;
	int state;
};