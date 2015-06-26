#pragma once

#include "EngineDLL.h"
#include "ShaderGLWrapper.h"

class ShaderManager
{
private:
	ShaderGLWrapper *mCurrentShader;
	ShaderGLWrapper mSpriteShader;

public:
	ENGINE_API ShaderManager();
	ENGINE_API ~ShaderManager();

	ENGINE_API void SetCurrentShader(ShaderGLWrapper *shader);
	ENGINE_API ShaderGLWrapper *GetCurrentShader();

	ShaderGLWrapper &GetSpriteShader();
};

