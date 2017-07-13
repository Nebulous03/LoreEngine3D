#include "Timer.h"

Timer::Timer()
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	_frequency = 1.0 / frequency.QuadPart;
	QueryPerformanceCounter(&_startTime);
}

void Timer::reset()
{
	QueryPerformanceCounter(&_startTime);
}

double Timer::elapsed()
{
	QueryPerformanceCounter(&_currentTime);
	unsigned __int64 cycles = _currentTime.QuadPart - _startTime.QuadPart;
	return (double)(cycles * _frequency);
}