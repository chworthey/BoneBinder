#pragma once

#include "ShaderGLWrapper.h"
#include <memory>
#include <string>
#include <glm/glm.hpp>

class ShaderManager;

class Shader
{
private:
	std::shared_ptr<ShaderGLWrapper> mShader;
public:
	Shader(std::string fileName, ShaderManager &shaderManager);
	ENGINE_API void Bind();
	void SetModelViewProjectionMatrixUniform(glm::mat4 transform);
};