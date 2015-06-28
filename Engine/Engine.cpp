#include "Engine.h"
#include <GL/glew.h>
#include "Time.h"
#include "Model.h"
#include <iostream>
#include "FeatureIncludes.h"


Engine::Engine(EngineInitialSettings settings)
: mInputManager(),
mWindow(settings.GetWindowWidth(), settings.GetWindowHeight(), settings.GetWindowTitle(), mInputManager),
mTime(0.0),
mShaderManager(),
mContentManager(mShaderManager, mWindow),
mRenderer(mShaderManager, mWindow),
mCurrentInputState()
{
}

#if USE_PHYSICS_OPTIMIZED_ENGINE
void Engine::Run()
{
	double previousTime = GetCurrentTime();
	double lag = 0.0;
	double startTime = previousTime;

	// Implement engine loop with fixed update time step, and variable time stepped rendering
	// Has 1 frame delay to ensure smooth rendering (interpolation-only)
	while (!mWindow.IsClosed())
	{           
		double currentTime = GetCurrentTime();
		double deltaTime = currentTime - previousTime;

		if (deltaTime > 0.25)
			deltaTime = 0.25;

		previousTime = currentTime;
		lag += deltaTime;

		processInput();

		while (lag >= kElapsedUpdateTime)
		{

			Time t(GetCurrentTime() - startTime, kElapsedUpdateTime);

			try
			{
				Update(t);
			}
			catch (EngineException &e)
			{
				mWindow.ShowNotificationMessageBox(e.What(), MessageType::ERROR_MESSAGE_TYPE);
			}
			lag -= kElapsedUpdateTime;
		}

		try
		{
			Draw(lag / kElapsedUpdateTime);
		}
		catch (EngineException &e)
		{
			mWindow.ShowNotificationMessageBox(e.What(), MessageType::ERROR_MESSAGE_TYPE);
		}

		mWindow.SwapBuffers();
		mWindow.UpdateClosed();
	}
}
#else
void Engine::Run()
{
	double previousTime = GetCurrentTime();
	double lag = 0.0;
	double startTime = previousTime;

	while (!mWindow.IsClosed())
	{
		double currentTime = GetCurrentTime();
		double deltaTime = currentTime - previousTime;

		previousTime = currentTime;

		Time t(GetCurrentTime() - startTime, deltaTime);

		mWindow.Update();
		mCurrentInputState = mInputManager.GenerateInputState();

		try
		{
			Update(t);
		}
		catch (EngineException &e)
		{
			mWindow.ShowNotificationMessageBox(e.What(), MessageType::ERROR_MESSAGE_TYPE);
		}

		try
		{
			Draw();
		}
		catch (EngineException &e)
		{
			mWindow.ShowNotificationMessageBox(e.What(), MessageType::ERROR_MESSAGE_TYPE);
		}

		mWindow.SwapBuffers();
	}
}
#endif

double Engine::GetCurrentTime() const
{
	return mWindow.GetTicks() / 1000.0;
}