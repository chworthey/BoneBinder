#include "BoneBinderEngine.h"
#include <GL\glew.h>
#include "PrimitivesHelper.h"
#include "Renderer.h"

#include <glm/gtc/matrix_inverse.hpp>

BoneBinderEngine::BoneBinderEngine(EngineInitialSettings settings)
: Engine(settings),
//mShader(GetContentManager().LoadShaderFromFile("./Resources/breakVisualizerShader")),
mShader(GetContentManager().LoadShaderFromFile("./Resources/basicShader")),

mCamera(
	glm::vec3(0.0f, 0.0f, -3.0f), 
	glm::vec3(0.0f, 0.0f, 0.0f), 
	45.0f, 
	GetDisplayWindow()),

mTestModel(
	GetContentManager().LoadModelsFromFile("./Resources/TestModel3.fbx")[0]),

mTestTexture("./Resources/Stupid.png"),
mRockTexture("./Resources/rock-cliff-texture.jpg"),
mTestTexturePosition(0.0f, 0.0f)
{
}

void BoneBinderEngine::Update(const Time &engineTime)
{
	mCamera.SetPosition(
		glm::vec3(
			(float)std::cos(engineTime.GetTotalTimeInSeconds()),
			(float)std::sin(engineTime.GetTotalTimeInSeconds()), 
			0.5f) * 4.0f);

	InputState &input = GetInputState();
	const float pixelsPerSecond = 100.0f;

	if (input.GetIsKeyboardKeyDown(KeyboardKey::LEFT))
		mTestTexturePosition.x -= (float)engineTime.GetElapsedTimeInSeconds() * pixelsPerSecond;
	if (input.GetIsKeyboardKeyDown(KeyboardKey::RIGHT))
		mTestTexturePosition.x += (float)engineTime.GetElapsedTimeInSeconds() * pixelsPerSecond;
	if (input.GetIsKeyboardKeyDown(KeyboardKey::UP))
		mTestTexturePosition.y -= (float)engineTime.GetElapsedTimeInSeconds() * pixelsPerSecond;
	if (input.GetIsKeyboardKeyDown(KeyboardKey::DOWN))
		mTestTexturePosition.y += (float)engineTime.GetElapsedTimeInSeconds() * pixelsPerSecond;
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

	if (!mShader)
		return;

	mRockTexture.Bind();
	mShader->Bind();
	
	glm::vec4 diffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	glm::mat4 world(1.0);
	glm::mat4 worldInverseTranspose = glm::transpose(glm::inverse(world));
	glm::vec3 eyePosition = mCamera.GetPosition();
	int specularPower = 22;
	glm::vec3 emissiveColor = glm::vec3(GetInputState().GetMouseScrollPosition() / 50.0f);
	glm::vec3 specularColor(0.3f, 0.3f, 0.3f);

	glm::vec3 dirLight0Direction = glm::normalize(glm::vec3(1.0, 0.75, 2.0));
	glm::vec3 dirLight0DiffuseColor(0.45f, 0.6, 0.2f);
	glm::vec3 dirLight0SpecularColor = specularColor;
	glm::vec3 dirLight1Direction = glm::normalize(glm::vec3(1.0, 0.15, 0.0));
	glm::vec3 dirLight1DiffuseColor(0.6, 0.45f, 0.2f);
	glm::vec3 dirLight1SpecularColor = specularColor;
	glm::vec3 dirLight2Direction = glm::normalize(glm::vec3(5.0, 0.75, 2.0));
	glm::vec3 dirLight2DiffuseColor(0.6, 0.2f, 0.45f);
	glm::vec3 dirLight2SpecularColor = specularColor;
	
	GLuint uniformLocation = mShader->GetUniformLocation("DiffuseColor");
	glUniform4fv(uniformLocation, 1, &diffuseColor[0]);
	uniformLocation = mShader->GetUniformLocation("WorldOnly");
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &world[0][0]);
	uniformLocation = mShader->GetUniformLocation("WorldInverseTranspose");
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &worldInverseTranspose[0][0]);
	uniformLocation = mShader->GetUniformLocation("EyePosition");
	glUniform3fv(uniformLocation, 1, &eyePosition[0]);
	uniformLocation = mShader->GetUniformLocation("SpecularPower");
	glUniform1i(uniformLocation, specularPower);
	uniformLocation = mShader->GetUniformLocation("EmissiveColor");
	glUniform3fv(uniformLocation, 1, &emissiveColor[0]);
	uniformLocation = mShader->GetUniformLocation("SpecularColor");
	glUniform3fv(uniformLocation, 1, &specularColor[0]);

	uniformLocation = mShader->GetUniformLocation("DirLight0Direction");
	glUniform3fv(uniformLocation, 1, &dirLight0Direction[0]);
	uniformLocation = mShader->GetUniformLocation("DirLight0DiffuseColor");
	glUniform3fv(uniformLocation, 1, &dirLight0DiffuseColor[0]);
	uniformLocation = mShader->GetUniformLocation("DirLight0SpecularColor");
	glUniform3fv(uniformLocation, 1, &dirLight0SpecularColor[0]);
	uniformLocation = mShader->GetUniformLocation("DirLight1Direction");
	glUniform3fv(uniformLocation, 1, &dirLight1Direction[0]);
	uniformLocation = mShader->GetUniformLocation("DirLight1DiffuseColor");
	glUniform3fv(uniformLocation, 1, &dirLight1DiffuseColor[0]);
	uniformLocation = mShader->GetUniformLocation("DirLight1SpecularColor");
	glUniform3fv(uniformLocation, 1, &dirLight1SpecularColor[0]);
	uniformLocation = mShader->GetUniformLocation("DirLight2Direction");
	glUniform3fv(uniformLocation, 1, &dirLight2Direction[0]);
	uniformLocation = mShader->GetUniformLocation("DirLight2DiffuseColor");
	glUniform3fv(uniformLocation, 1, &dirLight2DiffuseColor[0]);
	uniformLocation = mShader->GetUniformLocation("DirLight2SpecularColor");
	glUniform3fv(uniformLocation, 1, &dirLight2SpecularColor[0]);

	GetRenderer().RenderModel(mTestModel, glm::mat4(1), mCamera);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GetRenderer().RenderTexture(mTestTexture, mTestTexturePosition);
	GetRenderer().RenderTexture(mTestTexture, GetInputState().GetMousePosition() -
		mTestTexture.GetTextureSize() / 2.0f);
}