#pragma once

#include "EngineDLL.h"
#include <string>

void Assert(bool assertion, std::string message = "");
void Assert(void *assertion, std::string message = "");