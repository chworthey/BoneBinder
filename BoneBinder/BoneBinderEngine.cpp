#include "BoneBinderEngine.h"
#include "GL\glew.h"
#include "PrimitivesHelper.h"
#include "Renderer.h"
#include "glm/glm.hpp"

BoneBinderEngine::BoneBinderEngine(EngineInitialSettings settings)
: Engine(settings),
mShader(GetContentManager().LoadShaderFromFile("./Resources/basicShader")),

mCamera(
	glm::vec3(0.0f, 0.0f, -3.0f), 
	glm::vec3(0.0f, 0.0f, 0.0f), 
	45.0f, 
	GetDisplayWindow()),

mTestModel(
	PrimitivesHelper::CreateTriangle(
		glm::vec3(-0.5f, 0.0f, 0.0), 
		glm::vec3(0.0f, 0.5f, 0.0f),
		glm::vec3(0.5f, -0.5f, 0.0f)))
{
}

void BoneBinderEngine::Update(const Time &engineTime)
{
	mCamera.SetPosition(
		glm::vec3(
			(float)std::cos(engineTime.GetTotalTimeInSeconds()),
			(float)std::sin(engineTime.GetTotalTimeInSeconds()), 
			0.5f) * 4.0f);
}

void BoneBinderEngine::Draw(double alpha)
{
	glClearColor(0.0f, 0.0f, 0.0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	mShader.Bind();

	GetRenderer().Render(mTestModel, mCamera);
}