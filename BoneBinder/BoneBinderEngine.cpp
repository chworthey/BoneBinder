#include "BoneBinderEngine.h"
#include "GL\glew.h"

BoneBinderEngine::BoneBinderEngine()
{

}

EngineInitialSettings BoneBinderEngine::Initialize(EngineInitialSettings settingsDefault)
{
	settingsDefault.SetWindowTitle("Bone Binder");
	return settingsDefault;
}

void BoneBinderEngine::Update(double deltaTime)
{

}

void BoneBinderEngine::Draw(double alpha)
{
	glClearColor(1.0f, 0.0f, 0.0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}