#include "BoneBinderEngine.h"
#include "GL\glew.h"
#include "PrimitivesHelper.h"
#include "Renderer.h"
#include "glm/glm.hpp"

BoneBinderEngine::BoneBinderEngine(EngineInitialSettings settings)
: Engine(settings),
mShader(GetContentManager().LoadShaderFromFile("./Resources/breakVisualizerShader")),

mCamera(
	glm::vec3(0.0f, 0.0f, -3.0f), 
	glm::vec3(0.0f, 0.0f, 0.0f), 
	45.0f, 
	GetDisplayWindow()),

mTestModel(
	GetContentManager().LoadModelsFromFile("./Resources/TestModel3.fbx")[0]),

mTestTexture("./Resources/Stupid.png")
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

void BoneBinderEngine::Draw()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glClearColor(0.0f, 0.0f, 0.0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearDepth(1.0f);
	glClear(GL_DEPTH_BUFFER_BIT);

	glDisable(GL_BLEND);

	if (mShader)
		mShader->Bind();

	GetRenderer().RenderModel(mTestModel, glm::mat4(1), mCamera);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GetRenderer().RenderTexture(mTestTexture, glm::vec2((float)GetDisplayWindow().GetWidth(), 
		(float)GetDisplayWindow().GetHeight()) / 2.0f -
		glm::vec2((float)mTestTexture.getWidth(), (float)mTestTexture.getHeight()) / 2.0f);
}