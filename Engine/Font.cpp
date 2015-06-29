#include "Font.h"
#include <GL/glew.h>

Font::Font(std::string fileName, float fontSize)
: mFont(new FontGLWrapper(fileName, fontSize))
{
}

Font::~Font()
{
}

void Font::BindCharacterTexture(char c, int &outPixelAdvancement, glm::vec2 &outTextureSize, glm::vec2 &outPositionOffset)
{
	if (!mFont)
		return;

	auto mp = mFont->GetCharacterMap();

	if (mp.find(c) == mp.end())
		return;

	auto ch = mp[c];
	glBindTexture(GL_TEXTURE_2D, ch.mTexture);

	outPixelAdvancement = ch.mAdvancement;
	outTextureSize = ch.mTextureSize;
	outPositionOffset = ch.mPositionOffset;
}
