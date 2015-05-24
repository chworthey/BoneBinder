// Time.cpp 
// compile with: cl /EHsc Time.cpp /link Engine.lib

#include "Time.h"

Time::Time(double totalTimeInSeconds, double elapsedTimeInSeconds)
	: mTotalTime(totalTimeInSeconds),
	mElapsedTime(elapsedTimeInSeconds)
{
}