#pragma once

#define PI 3.14159265359

inline float toRadians(const float degrees)
{
	return degrees * ((float)PI / 180.0f);
}