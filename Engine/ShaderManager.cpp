#include "ShaderManager.h"


ShaderManager::ShaderManager()
{
}


ShaderManager::~ShaderManager()
{
}

void ShaderManager::SetCurrentShader(Shader *shader)
{
	mCurrentShader = shader;
}

Shader *ShaderManager::GetCurrentShader()
{
	return mCurrentShader;
}
