#pragma once

#include "EngineDLL.h"
#include "Time.h"

class IUpdateable
{
public:
	ENGINE_API virtual void Update(const Time &engineTime) = 0;
};