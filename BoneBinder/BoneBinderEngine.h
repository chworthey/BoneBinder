#pragma once

#include "Engine.h"
#include "EngineInitialSettings.h"
#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "Time.h"
#include "Texture2D.h"
#include "Font.h"
#include <glm/glm.hpp>

class BoneBinderEngine : public Engine
{
private:
	std::shared_ptr<Shader> mShader;
	Camera mCamera;
	Model mTestModel;
	Texture2D mTestTexture;
	Texture2D mRockTexture;
	glm::vec2 mTestTexturePosition;
	Font mFont;
	double mElapsedTime;
	double mLastUpdateTime;

public:
	BoneBinderEngine(EngineInitialSettings settings);

	void Update(const Time &engineTime) override;
	void Draw() override;
};

