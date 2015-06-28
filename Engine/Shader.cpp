#include "Shader.h"
#include "ShaderManager.h"
#include "Assert.h"

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

GLuint Shader::GetUniformLocation(std::string name)
{
	if (mShader)
		return mShader->GetUniformLocation(name);
	else
	{
		Assert(false, "No shader.");
		return 0;
	}
}

