#pragma once

//@hack: glm invert and transpose will not work without this
#define assert(bool)

#include "EngineDLL.h"
#include "IUpdateable.h"
#include "IDrawable.h"
#include "EngineInitialSettings.h"
#include "ContentManager.h"
#include "Renderer.h"
#include "DisplayWindow.h"
#include "ShaderManager.h"
#include "InputManager.h"
#include "InputState.h"

class Engine : public IUpdateable, public IDrawable
{
private:
#if USE_PHYSICS_OPTIMIZED_ENGINE
	const double kElapsedUpdateTime = 0.01;
#endif
	InputManager mInputManager;
	DisplayWindow mWindow;
	double mTime;
	ShaderManager mShaderManager;
	ContentManager mContentManager;
	Renderer mRenderer;
	InputState mCurrentInputState;

public:
	ENGINE_API Engine(EngineInitialSettings settings);
	ENGINE_API void Run();

protected:
	ENGINE_API double GetCurrentTime() const;
	ENGINE_API const ContentManager &GetContentManager() const { return mContentManager; }
	ENGINE_API Renderer &GetRenderer() { return mRenderer; }
	ENGINE_API DisplayWindow &GetDisplayWindow() { return mWindow; }
	ENGINE_API InputState &GetInputState() { return mCurrentInputState; }

private:
	void operator=(const Engine &rhs) {}
};

