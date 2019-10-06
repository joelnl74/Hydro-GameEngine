#include <time.h>
#include <windows.h>
#include <cstdio>

//DeltaTime
#define GAME_STEP_TIME_MSS = 1000.0 / 60.0

class Time
{
private:
	LARGE_INTEGER EndCounter, LastCounter, frequency;
	INT64 freq;
public:
	float deltaTime;
	void StartUp();
	void ShutDown();
	void BeginFrame();
	void EndFrame();
	static Time * m_Instance;
};