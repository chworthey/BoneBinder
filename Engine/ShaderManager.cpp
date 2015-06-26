#include "ShaderManager.h"


ShaderManager::ShaderManager()
: mSpriteShader("./Resources/spriteShader", *this)
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

ShaderGLWrapper & ShaderManager::GetSpriteShader()
{
	return mSpriteShader;
}
