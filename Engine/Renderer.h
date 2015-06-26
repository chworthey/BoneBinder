#pragma once

#include "EngineDLL.h"
#include "glm/glm.hpp"

class Model;
class Camera;
class ShaderManager;
class Texture2D;
class DisplayWindow;

class Renderer
{
private:
	ShaderManager &mShaderManager;
	DisplayWindow &mDisplayWindow;

public:
	ENGINE_API Renderer(ShaderManager &shaderManager, DisplayWindow &displayWindow);

	ENGINE_API ~Renderer();

	ENGINE_API void RenderModel(const Model &model, const glm::mat4 &world, const Camera &camera);
	ENGINE_API void RenderTexture(Texture2D &texture, const glm::vec2 &position);
};

