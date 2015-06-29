#pragma once

#include "EngineDLL.h"
#include "FontGLWrapper.h"
#include <memory>
#include <string>
#include <glm/glm.hpp>

class Font
{
private:
	std::shared_ptr<FontGLWrapper> mFont;

public:
	ENGINE_API Font(std::string fileName, float fontSize);
	ENGINE_API ~Font();
	void BindCharacterTexture(char c, int &outPixelAdvancement, glm::vec2 &outTextureSize, glm::vec2 &outPositionOffset);
};

