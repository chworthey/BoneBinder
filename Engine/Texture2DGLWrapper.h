#pragma once

#include <string>
#include "GL/glew.h"

class Texture2DGLWrapper
{
private:
	GLuint mTexture;
	int mWidth;
	int mHeight;

public:
	Texture2DGLWrapper(std::string fileName);
	~Texture2DGLWrapper();

	int getWidth() const { return mWidth; }
	int getHeight() const { return mHeight; }

	void Bind();

private:
	void throwLoadError(std::string fileName);
};

