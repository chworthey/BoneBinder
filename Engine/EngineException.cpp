#include "EngineException.h"


EngineException::EngineException(std::string name, std::string errorMsg)
: mName(name),
mErrorMsg(errorMsg)
{
}


EngineException::~EngineException()
{
}

std::string EngineException::What() const
{
	return mName + " Exception. Error message: " + mErrorMsg;
}
