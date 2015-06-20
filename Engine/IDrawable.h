#pragma once

#include "EngineDLL.h"
#include "FeatureIncludes.h"

class IDrawable
{
public:
#if USE_PHYSICS_OPTIMIZED_ENGINE
	ENGINE_API virtual void Draw(double alpha) = 0;
#else
	ENGINE_API virtual void Draw() = 0;
#endif
};