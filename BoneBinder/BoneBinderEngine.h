#pragma once

#include "Engine.h"
#include "EngineInitialSettings.h"
#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "Time.h"

class BoneBinderEngine : public Engine
{
private:
	Shader mShader;
	Camera mCamera;
	Model mTestModel;

public:
	BoneBinderEngine(EngineInitialSettings settings);

	void Update(const Time &engineTime) override;
	void Draw(double alpha) override;
};

