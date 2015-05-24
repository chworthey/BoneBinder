#pragma once

#include "EngineDLL.h"
#include "IUpdateable.h"
#include "IDrawable.h"
#include "EngineInitialSettings.h"

class Engine : public IUpdateable, public IDrawable
{
private:
	const double kElapsedUpdateTime = 0.01;
	double mTime;

public:
	ENGINE_API Engine();

	ENGINE_API void Run();

protected:
	ENGINE_API virtual EngineInitialSettings Initialize(EngineInitialSettings settingsDefault);
	ENGINE_API double GetCurrentTime() const;

private:
	void processInput();
	Engine(const Engine &rhs) {}
	void operator=(const Engine &rhs) {}
};

