#pragma once

#include "EngineDLL.h"

class Time
{
private:
	double mElapsedTime;
	double mTotalTime;

public:
	ENGINE_API Time(double totalTimeInSeconds, double elapsedTimeInSeconds);

	ENGINE_API double GetElapsedTimeInSeconds() const { return mElapsedTime; }
	ENGINE_API double GetTotalTimeInSeconds() const { return mTotalTime; }
};