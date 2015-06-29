#pragma once

#include "EngineDLL.h"
#include <string>
#include <map>
#include <GL/glew.h>
#include <glm/glm.hpp>

struct FontGLCharacter
{
public:
	GLuint mTexture;
	int mAdvancement;
	glm::vec2 mPositionOffset;
	glm::vec2 mTextureSize;
};

class FontGLWrapper
{
private:

	std::map<char, FontGLCharacter> mCharacters;
public:
	FontGLWrapper(const std::string &fileName, float fontSize);
	~FontGLWrapper();

	std::map<char, FontGLCharacter> &GetCharacterMap();
};

