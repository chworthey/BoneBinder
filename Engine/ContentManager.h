#pragma once

#include "EngineDLL.h"
#include <string>
#include "EngineException.h"
#include <vector>

class Model;

class ContentManager
{
public:
	ContentManager();
	ENGINE_API ~ContentManager();

	ENGINE_API std::vector<Model> LoadModelsFromFile(std::string path);

private:
	void throwLoadException(std::string message) const;
};

class ContentLoadException : public EngineException
{
public:
	ContentLoadException(std::string errorMsg);
};