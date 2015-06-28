#include "Texture2D.h"
#include "Assert.h"

Texture2D::Texture2D(std::string fileName)
: mTexture(new Texture2DGLWrapper(fileName))
{
}


Texture2D::~Texture2D()
{
}

void Texture2D::Bind()
{
	Assert(mTexture.get());
	if (mTexture)
		mTexture->Bind();
}

int Texture2D::GetWidth() const
{
	Assert(mTexture.get());
	if (mTexture)
		return mTexture->getWidth();
	else
		return -1;
}

int Texture2D::GetHeight() const
{
	Assert(mTexture.get());
	if (mTexture)
		return mTexture->getHeight();
	else
		return -1;
}

glm::vec2 Texture2D::GetTextureSize() const
{
	Assert(mTexture.get());
	if (mTexture)
		return glm::vec2(mTexture->getWidth(), mTexture->getHeight());
	else
		return glm::vec2();
}
