#include <time.h>
#include <cstdio>
class Timer
{
private:
	/* Here will be the instance stored. */
	static Timer* instance;

	double currentTime;
	/* Private constructor to prevent instancing. */
	Timer();

public:
	void getTime()
	{
		printf("%f time:", currentTime);
	}
	/* Static access method. */
	static Timer* getInstance();
	
};

/* Null, because instance will be initialized on demand. */
Timer* Timer::instance = 0;

Timer* Timer::getInstance()
{
	if (instance == 0)
	{
		instance = new Timer();
	}

	return instance;
}

Timer::Timer()
{
}
