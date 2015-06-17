#include "ShaderManager.h"


ShaderManager::ShaderManager()
{
}


ShaderManager::~ShaderManager()
{
}

void ShaderManager::SetCurrentShader(ShaderGLWrapper *shader)
{
	mCurrentShader = shader;
}

ShaderGLWrapper *ShaderManager::GetCurrentShader()
{
	return mCurrentShader;
}
