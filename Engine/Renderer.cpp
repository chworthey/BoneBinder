#include "Engine.h"
#include "Renderer.h"
#include "Vertex.h"
#include "Model.h"
#include "Camera.h"
#include "Shader.h"
#include "ShaderManager.h"
#include "PrimitivesHelper.h"
#include "Rectangle.h"
#include "Texture2D.h"
#include "glm/gtx/transform.hpp"
#include "Font.h"

#include <algorithm>

Renderer::Renderer(ShaderManager &shaderManager, DisplayWindow &displayWindow)
: mShaderManager(shaderManager),
mDisplayWindow(displayWindow)
{
}

Renderer::~Renderer()
{
}

void Renderer::RenderModel(const Model &model, const glm::mat4 &world, const Camera &camera)
{
	auto shader = mShaderManager.GetCurrentShader();

	if (!shader)
		return;

	glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * world;

	shader->SetModelViewProjectionMatrixUniform(mvp);

	auto meshes = model.GetMeshes();

	for (auto mesh : meshes)
		mesh->Draw();
}

void Renderer::RenderTexture(Texture2D &texture, const glm::vec2 &position, const glm::vec4 &color)
{
	texture.Bind();
	renderTexturedQuad(position, texture.GetTextureSize(), texture.GetTextureSize(), 
		Rectangle(0.0f, 0.0f, (float)texture.GetWidth(), (float)texture.GetHeight()), color);
}

void Renderer::RenderTexture(Texture2D &texture, const Rectangle &targetArea, const Rectangle &sourceArea, const glm::vec4 &color)
{
	texture.Bind();

	Rectangle source = sourceArea;

	source.SetLeft(std::fmaxf(0.0f, std::fminf((float)texture.GetWidth(), sourceArea.GetLeft())));
	source.SetTop(std::fmaxf(0.0f, std::fminf((float)texture.GetHeight(), sourceArea.GetTop())));
	source.SetRight(std::fmaxf(0.0f, std::fminf((float)texture.GetWidth(), sourceArea.GetRight())));
	source.SetBottom(std::fmaxf(0.0f, std::fminf((float)texture.GetHeight(), sourceArea.GetBottom())));

	if (source.GetRight() > texture.GetWidth())
		source.SetRight((float)texture.GetWidth());
	if (source.GetBottom() > texture.GetHeight())
		source.SetBottom((float)texture.GetHeight());

	renderTexturedQuad(targetArea.GetLeftTop(), targetArea.CalculateSize(), texture.GetTextureSize(), source, color);
}

void Renderer::RenderText(Font &font, const std::string &text, const glm::vec2 &position, const glm::vec4 &color)
{
	glm::vec2 pos = position;
	for (auto ch : text)
	{
		int advancement = 0;
		glm::vec2 textureSize(0.0f, 0.0f);
		glm::vec2 positionOffset(0.0f, 0.0f);
		font.BindCharacterTexture(ch, advancement, textureSize, positionOffset);
		renderTexturedQuad(pos + positionOffset, textureSize, textureSize, Rectangle(0, 0, textureSize.x, textureSize.y), color);
		pos.x += advancement;
	}
}

void Renderer::renderTexturedQuad(const glm::vec2 &position, const glm::vec2 &targetSize, const glm::vec2 &textureSize,
	const Rectangle &sourceArea, const glm::vec4 &color)
{
	mShaderManager.GetSpriteShader().Bind();

	auto shader = mShaderManager.GetCurrentShader();

	glm::mat4 mvp = glm::ortho(0.0f, (float)mDisplayWindow.GetWidth(), (float)mDisplayWindow.GetHeight(), 0.0f)
		* glm::translate(glm::vec3(position, 0));
	shader->SetModelViewProjectionMatrixUniform(mvp);
	glUniform4fv(shader->GetUniformLocation("SpriteColor"), 1, &color[0]);

	float texWidth = targetSize.x;
	float texHeight = targetSize.y;

	float topRatio = 1.0f - sourceArea.GetTop() / textureSize.y;
	float bottomRatio = 1.0f - sourceArea.GetBottom() / textureSize.y;
	float leftRatio = sourceArea.GetLeft() / textureSize.x;
	float rightRatio = sourceArea.GetRight() / textureSize.x;

	Model quad = PrimitivesHelper::CreateQuad(
		Vertex(
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec2(leftRatio, topRatio),
			glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(
			glm::vec3(texWidth, 0.0f, 0),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec2(rightRatio, topRatio),
			glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(
			glm::vec3(texWidth, texHeight, 0),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec2(rightRatio, bottomRatio),
			glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(
			glm::vec3(0.0f, texHeight, 0),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec2(leftRatio, bottomRatio),
			glm::vec3(0.0f, 0.0f, 1.0f)));

	auto meshes = quad.GetMeshes();

	for (auto mesh : meshes)
		mesh->Draw();
}
