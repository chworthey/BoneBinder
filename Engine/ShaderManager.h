#pragma once

#include "EngineDLL.h"

class Shader;

class ShaderManager
{
private:
	Shader *mCurrentShader;

public:
	ENGINE_API ShaderManager();
	ENGINE_API ~ShaderManager();

	ENGINE_API void SetCurrentShader(Shader *shader);
	ENGINE_API Shader *GetCurrentShader();
};

