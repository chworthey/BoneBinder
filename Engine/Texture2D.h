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

	ENGINE_API void Bind();
	
	ENGINE_API int GetWidth() const;
	ENGINE_API int GetHeight() const;
};

