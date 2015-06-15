#pragma once

#include "EngineDLL.h"
#include <glm\glm.hpp>
#include "Model.h"

class PrimitivesHelper
{
public:
	ENGINE_API static Model CreateTriangle(glm::vec3 a, glm::vec3 b, glm::vec3 c);
};

