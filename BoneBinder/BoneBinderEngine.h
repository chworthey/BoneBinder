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
	std::vector<Model> mTestModels;
	std::shared_ptr<Texture2D> mTestTexture;
	std::shared_ptr<Texture2D> mRockTexture;
	glm::vec2 mTestTexturePosition;
	std::shared_ptr<Font> mFont;
	double mElapsedTime;
	double mLastUpdateTime;

public:
	BoneBinderEngine(EngineInitialSettings settings);

	void Update(const Time &engineTime) override;
	void Draw() override;
};

