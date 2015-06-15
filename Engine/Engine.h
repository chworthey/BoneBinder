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
	const double kElapsedUpdateTime = 0.01;
	double mTime;
	ContentManager mContentManager;
	ShaderManager mShaderManager;
	Renderer mRenderer;
	DisplayWindow mWindow;

public:
	ENGINE_API Engine(EngineInitialSettings settings);
	ENGINE_API void Run();

	ShaderManager &GetShaderManager() { return mShaderManager; }

protected:
	ENGINE_API double GetCurrentTime() const;
	ENGINE_API const ContentManager &GetContentManager() const { return mContentManager; }
	ENGINE_API Renderer &GetRenderer() { return mRenderer; }
	ENGINE_API DisplayWindow &GetDisplayWindow() { return mWindow; }

private:
	void processInput();
	void operator=(const Engine &rhs) {}
};

