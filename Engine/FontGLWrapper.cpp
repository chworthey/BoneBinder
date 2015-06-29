#include "FontGLWrapper.h"
#include <freetype/ft2build.h>
#include FT_FREETYPE_H
#include "EngineException.h"
#include <vector>

const std::string kExceptionName = "Font Load";

FontGLWrapper::FontGLWrapper(const std::string &fileName, float fontSize)
: mCharacters()
{
	FT_Library library;

	FT_Error e = FT_Init_FreeType(&library);
	if (e)
		throw EngineException(kExceptionName, "Font loading library could not be initialized.");

	FT_Face face;

	e = FT_New_Face(library, fileName.c_str(), 0, &face);
	if (e == FT_Err_Unknown_File_Format)
		throw EngineException(kExceptionName, "This font format is not supported.");
	else if (e)
		throw EngineException(kExceptionName, "Font file could not be opened or read.");

	e = FT_Set_Char_Size(
		face,
		0,						// same as vertical size
		(int)(64.0f * fontSize),// parameter is in 1/64 of dot size
		0,						// same as vertical dpi
		72);					// hard-coded dpi (pretty typical for most screens)
	if (e)
		throw EngineException(kExceptionName, "Unsupported font size.");

	FT_GlyphSlot slot = face->glyph;

	for (int n = 0; n < 256; n++)
	{
		e = FT_Load_Char(face, (char)n, FT_LOAD_RENDER);
		if (e)
			continue;

		FT_Bitmap &bmp = slot->bitmap;

		if (!slot->bitmap.buffer)
			continue;

		unsigned char *pixels = &bmp.buffer[bmp.width * (bmp.rows - 1)];

		int numPixels = bmp.width * bmp.rows;
		std::vector<GLubyte> glBytes;

		for (unsigned int i = 0; i < bmp.rows; i++)
		{
			for (unsigned int n = 0; n < bmp.width; n++)
			{
				glBytes.push_back(0xFF);
				glBytes.push_back(0xFF);
				glBytes.push_back(0xFF);
				glBytes.push_back(pixels[n]);
			}
			pixels -= bmp.pitch;
		}

		FontGLCharacter c;

		glGenTextures(1, &c.mTexture);
		glBindTexture(GL_TEXTURE_2D, c.mTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bmp.width, bmp.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid *)&glBytes[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);

		if (glGetError())
			throw EngineException(kExceptionName, "Open GL threw an error while creating a texture for the font.");

		c.mPositionOffset = glm::vec2(slot->bitmap_left, -slot->bitmap_top + fontSize);
		c.mAdvancement = (int)(slot->advance.x / 64UL);
		c.mTextureSize = glm::vec2(bmp.width, bmp.rows);
		mCharacters[(char)n] = c;
	}
}


FontGLWrapper::~FontGLWrapper()
{
	for (auto i : mCharacters)
	{
		glDeleteTextures(1, &i.second.mTexture);
	}
}

std::map<char, FontGLCharacter> & FontGLWrapper::GetCharacterMap()
{
	return mCharacters;
}
