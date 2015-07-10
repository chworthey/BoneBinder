#pragma once

#include "EngineDLL.h"
#include "glm/glm.hpp"
#include <string>

class Model;
class Camera;
class ShaderManager;
class Texture2D;
class DisplayWindow;
class Font;
struct Rectangle;

class Renderer
{
private:
	ShaderManager &mShaderManager;
	DisplayWindow &mDisplayWindow;

public:
	ENGINE_API Renderer(ShaderManager &shaderManager, DisplayWindow &displayWindow);

	ENGINE_API ~Renderer();

	ENGINE_API void RenderModel(const Model &model, const glm::mat4 &world, const Camera &camera);
	ENGINE_API void RenderTexture(Texture2D &texture, const glm::vec2 &position, const glm::vec4 &color);
	ENGINE_API void RenderTexture(Texture2D &texture, const Rectangle &targetArea, const Rectangle &sourceArea,
		const glm::vec4 &color);
	ENGINE_API void RenderText(Font &font, const std::string &text, const glm::vec2 &position, const glm::vec4 &color);

private:
	void renderTexturedQuad(const glm::vec2 &position, const glm::vec2 &targetSize, const glm::vec2 &textureSize,
		const Rectangle &sourceArea, const glm::vec4 &color);
};

