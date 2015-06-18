#pragma once

#include "EngineDLL.h"

class Model;
class Camera;
class ShaderManager;

class Renderer
{
private:
	ShaderManager &mShaderManager;

public:
	ENGINE_API Renderer(ShaderManager &shaderManager);

	ENGINE_API ~Renderer();

	ENGINE_API void Render(Model &model, const Camera &camera);
};

