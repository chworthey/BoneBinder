#pragma once

#include "EngineDLL.h"
#include <string>
#include "EngineException.h"
#include <vector>
#include <memory>
#include <functional>
#include "Shader.h"

class Model;
class ShaderManager;
class DisplayWindow;

class ContentManager
{
private:
	ShaderManager &mShaderManager;
	DisplayWindow &mDisplayWindow;

public:
	ContentManager(ShaderManager &shaderManager, DisplayWindow &displayWindow);
	ENGINE_API ~ContentManager();

	ENGINE_API std::vector<Model> LoadModelsFromFile(std::string path) const;
	ENGINE_API std::shared_ptr<Shader> LoadShaderFromFile(std::string path) const;

private:
	void throwLoadException(std::string message) const;
};

class ContentLoadException : public EngineException
{
public:
	ContentLoadException(std::string errorMsg);
};