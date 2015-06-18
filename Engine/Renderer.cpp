#include "Engine.h"
#include "Renderer.h"
#include "Vertex.h"
#include "Model.h"
#include "Camera.h"
#include "Shader.h"
#include "ShaderManager.h"
#include <glm/glm.hpp>


Renderer::Renderer(ShaderManager &shaderManager)
: mShaderManager(shaderManager)
{
}

Renderer::~Renderer()
{
}

void Renderer::Render(Model &model, const Camera &camera)
{
	auto shader = mShaderManager.GetCurrentShader();

	if (!shader)
		return;

	glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix();

	shader->SetModelViewProjectionMatrixUniform(mvp);

	auto meshes = model.GetMeshes();

	for (auto mesh : meshes)
		mesh->Draw();
}
