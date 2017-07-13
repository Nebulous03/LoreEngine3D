#pragma once
#include <Windows.h>

class Timer
{
private:
	LARGE_INTEGER _startTime;
	LARGE_INTEGER _currentTime;
	double _frequency;
public:
	Timer();
	void reset();
	double elapsed();
};