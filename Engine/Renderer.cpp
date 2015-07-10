#include "Engine.h"
#include "Renderer.h"
#include "Vertex.h"
#include "Model.h"
#include "Camera.h"
#include "Shader.h"
#include "ShaderManager.h"
#include "PrimitivesHelper.h"
#include "Texture2D.h"
#include "glm/gtx/transform.hpp"
#include "Font.h"

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
	renderTexturedQuad(position, texture.GetTextureSize(), color);
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
		renderTexturedQuad(pos + positionOffset, textureSize, color);
		pos.x += advancement;
	}
}

void Renderer::renderTexturedQuad(const glm::vec2 &position, const glm::vec2 &textureSize, const glm::vec4 &color)
{
	mShaderManager.GetSpriteShader().Bind();

	auto shader = mShaderManager.GetCurrentShader();

	glm::mat4 mvp = glm::ortho(0.0f, (float)mDisplayWindow.GetWidth(), (float)mDisplayWindow.GetHeight(), 0.0f)
		* glm::translate(glm::vec3(position, 0));
	shader->SetModelViewProjectionMatrixUniform(mvp);
	glUniform4fv(shader->GetUniformLocation("SpriteColor"), 1, &color[0]);

	float texWidth = textureSize.x;
	float texHeight = textureSize.y;

	Model quad = PrimitivesHelper::CreateQuad(
		Vertex(
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec2(0.0f, 1.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(
			glm::vec3(texWidth, 0.0f, 0),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec2(1.0f, 1.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(
			glm::vec3(texWidth, texHeight, 0),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec2(1.0f, 0.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(
			glm::vec3(0.0f, texHeight, 0),
			glm::vec3(1.0f, 1.0f, 1.0f),
			glm::vec2(0.0f, 0.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)));

	auto meshes = quad.GetMeshes();

	for (auto mesh : meshes)
		mesh->Draw();
}
