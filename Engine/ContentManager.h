#pragma once

#include "EngineDLL.h"
#include <string>
#include "EngineException.h"
#include <vector>
#include "Shader.h"
#include "ShaderManager.h"

class Model;

class ContentManager
{
private:
	ShaderManager &mShaderManager;

public:
	ContentManager(ShaderManager &shaderManager);
	ENGINE_API ~ContentManager();

	ENGINE_API std::vector<Model> LoadModelsFromFile(std::string path) const;
	ENGINE_API Shader LoadShaderFromFile(std::string path) const;

private:
	void throwLoadException(std::string message) const;
};

class ContentLoadException : public EngineException
{
public:
	ContentLoadException(std::string errorMsg);
};