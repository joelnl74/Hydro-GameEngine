#include "Time.h"
Time *Time::m_Instance = 0;

void Time::StartUp()
{
	if (m_Instance == 0)
	{
		m_Instance = new Time();
		QueryPerformanceFrequency(&frequency);
		m_Instance->freq = frequency.QuadPart;
	}
}
void Time::ShutDown()
{
	delete m_Instance;
}
void Time::BeginFrame()
{
	QueryPerformanceCounter(&EndCounter);

	int counterElpased = EndCounter.QuadPart - LastCounter.QuadPart;
	INT32 msPerFrame = (1000 * counterElpased) / freq;
	//printf("miliseconds %i \n", msPerFrame);
}
void Time::EndFrame()
{
	LastCounter = EndCounter;
}