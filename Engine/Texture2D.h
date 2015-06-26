#pragma once

#include <memory>
#include "Texture2DGLWrapper.h"
#include "EngineDLL.h"

class Texture2D
{
private:
	std::shared_ptr<Texture2DGLWrapper> mTexture;
public:
	ENGINE_API Texture2D(std::string fileName);
	ENGINE_API ~Texture2D();

	void bind();
	
	ENGINE_API int getWidth() const;
	ENGINE_API int getHeight() const;
};

