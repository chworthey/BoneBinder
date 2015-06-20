#pragma once

#include "EngineDLL.h"
#include "IUpdateable.h"
#include "IDrawable.h"
#include "EngineInitialSettings.h"
#include "ContentManager.h"
#include "Renderer.h"
#include "DisplayWindow.h"
#include "ShaderManager.h"

class Engine : public IUpdateable, public IDrawable
{
private:
#if USE_PHYSICS_OPTIMIZED_ENGINE
	const double kElapsedUpdateTime = 0.01;
#endif
	double mTime;
	ShaderManager mShaderManager;
	ContentManager mContentManager;
	Renderer mRenderer;
	DisplayWindow mWindow;

public:
	ENGINE_API Engine(EngineInitialSettings settings);
	ENGINE_API void Run();

protected:
	ENGINE_API double GetCurrentTime() const;
	ENGINE_API const ContentManager &GetContentManager() const { return mContentManager; }
	ENGINE_API Renderer &GetRenderer() { return mRenderer; }
	ENGINE_API DisplayWindow &GetDisplayWindow() { return mWindow; }

private:
	void processInput();
	void operator=(const Engine &rhs) {}
};

