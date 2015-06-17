#pragma once

#include "EngineDLL.h"

class ShaderGLWrapper;

class ShaderManager
{
private:
	ShaderGLWrapper *mCurrentShader;

public:
	ENGINE_API ShaderManager();
	ENGINE_API ~ShaderManager();

	ENGINE_API void SetCurrentShader(ShaderGLWrapper *shader);
	ENGINE_API ShaderGLWrapper *GetCurrentShader();
};

