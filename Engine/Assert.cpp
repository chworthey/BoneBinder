#include "Assert.h"
#include "EngineException.h"

void Assert(bool assertion, std::string message /*= ""*/)
{
	if (assertion)
		return;

	EngineException e("Assert", message);
	throw e;
}

void Assert(void *assertion, std::string message /*= ""*/)
{
	if (assertion)
		return;

	EngineException e("Assert", message);
	throw e;
}
