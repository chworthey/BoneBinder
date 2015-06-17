#include "Shader.h"
#include "ShaderManager.h"

Shader::Shader(std::string fileName, ShaderManager &shaderManager)
: mShader(new ShaderGLWrapper(fileName, shaderManager))
{

}

void Shader::Bind()
{
	if (mShader)
		mShader->Bind();
}

void Shader::SetModelViewProjectionMatrixUniform(glm::mat4 transform)
{
	if (mShader)
		mShader->SetModelViewProjectionMatrixUniform(transform);
}

