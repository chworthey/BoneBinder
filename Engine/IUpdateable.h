#pragma once

#include "EngineDLL.h"

class IUpdateable
{
public:
	ENGINE_API virtual void Update(double deltaTime) = 0;
};