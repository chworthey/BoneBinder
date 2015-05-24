#pragma once

#include "EngineDLL.h"

class IDrawable
{
public:
	ENGINE_API virtual void Draw(double alpha) = 0;
};