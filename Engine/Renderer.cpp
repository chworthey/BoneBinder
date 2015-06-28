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

void Renderer::RenderTexture(Texture2D &texture, const glm::vec2 &position)
{
	texture.Bind();
	mShaderManager.GetSpriteShader().Bind();

	auto shader = mShaderManager.GetCurrentShader();

	glm::mat4 mvp = glm::ortho(0.0f, (float)mDisplayWindow.GetWidth(), (float)mDisplayWindow.GetHeight(), 0.0f) 
		* glm::translate(glm::vec3(position, 0));
	shader->SetModelViewProjectionMatrixUniform(mvp);

	float texWidth = (float)texture.GetWidth();
	float texHeight = (float)texture.GetHeight();

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
