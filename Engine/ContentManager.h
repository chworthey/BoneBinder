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
class Texture2D;
class Font;

class ContentManager
{
private:
	ShaderManager &mShaderManager;
	DisplayWindow &mDisplayWindow;

public:
	ContentManager(ShaderManager &shaderManager, DisplayWindow &displayWindow);
	ENGINE_API ~ContentManager();

	ENGINE_API std::vector<Model> LoadModelsFromFile(const std::string &path) const;
	ENGINE_API std::shared_ptr<Shader> LoadShaderFromFile(const std::string &path) const;
	ENGINE_API std::shared_ptr<Texture2D> LoadTextureFromFile(const std::string &path) const;
	ENGINE_API std::shared_ptr<Font> LoadFontFromFile(const std::string &path, float fontSize) const;

private:
	void throwLoadException(std::string message) const;
};

class ContentLoadException : public EngineException
{
public:
	ContentLoadException(std::string errorMsg);
};