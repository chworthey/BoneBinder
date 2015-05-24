#pragma once

#include "Engine.h"
#include "EngineInitialSettings.h"

class BoneBinderEngine : public Engine
{
public:
	BoneBinderEngine();

	EngineInitialSettings Initialize(EngineInitialSettings settingsDefault) override;
	void Update(double deltaTime) override;
	void Draw(double alpha) override;
};

