#pragma once

#include "EngineDLL.h"
#include <string>

class EngineException
{
private:
	std::string mName;
	std::string mErrorMsg;
public:
	ENGINE_API EngineException(std::string name, std::string errorMsg);
	ENGINE_API ~EngineException();
	ENGINE_API std::string What() const;
};

