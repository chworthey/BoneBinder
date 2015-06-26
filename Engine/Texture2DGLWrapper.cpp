#include "Texture2DGLWrapper.h"
#include "EngineException.h"
#include "FreeImage/FreeImage.h"
#include <vector>

Texture2DGLWrapper::Texture2DGLWrapper(std::string fileName)
{
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(fileName.c_str(), 0);
	FIBITMAP *tempImage = FreeImage_Load(format, fileName.c_str());
	FIBITMAP *data = FreeImage_ConvertTo32Bits(tempImage);
	if (data == nullptr)
		throwLoadError(fileName);

	mWidth = FreeImage_GetWidth(data);
	mHeight = FreeImage_GetHeight(data);

	std::vector<GLubyte> glBytes;
	char *pixels = (char *)FreeImage_GetBits(data);

	int numPixels = mWidth * mHeight;

	for (int i = 0; i < numPixels; i++)
	{
		glBytes.push_back(pixels[i * 4 + 2]);
		glBytes.push_back(pixels[i * 4 + 1]);
		glBytes.push_back(pixels[i * 4 + 0]);
		glBytes.push_back(pixels[i * 4 + 3]);
	}

	FreeImage_Unload(data);
	FreeImage_Unload(tempImage);

	glGenTextures(1, &mTexture);
	glBindTexture(GL_TEXTURE_2D, mTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid *)&glBytes[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (glGetError())
		throwLoadError(fileName);
}


Texture2DGLWrapper::~Texture2DGLWrapper()
{
	glDeleteTextures(1, &mTexture);
}

void Texture2DGLWrapper::Bind()
{
	glBindTexture(GL_TEXTURE_2D, mTexture);
}

void Texture2DGLWrapper::throwLoadError(std::string fileName)
{
	throw EngineException("Texture", "Failed to load texture: '" + fileName + "'.");
}
