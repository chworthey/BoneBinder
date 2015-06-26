#pragma once

#include "Engine.h"
#include "EngineInitialSettings.h"
#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "Time.h"
#include "Texture2D.h"

class BoneBinderEngine : public Engine
{
private:
	std::shared_ptr<Shader> mShader;
	Camera mCamera;
	Model mTestModel;
	Texture2D mTestTexture;

public:
	BoneBinderEngine(EngineInitialSettings settings);

	void Update(const Time &engineTime) override;
	void Draw() override;
};

