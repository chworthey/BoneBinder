#include "Engine.h"
#include "DisplayWindow.h"
#include <GL/glew.h>
#include <time.h>
#include "Time.h"

Engine::Engine()
: mTime(0.0)
{
}

EngineInitialSettings Engine::Initialize(EngineInitialSettings settingsDefault)
{
	return settingsDefault;
}

void Engine::Run()
{
	double previousTime = GetCurrentTime();
	double lag = 0.0;

	EngineInitialSettings settings = Initialize(EngineInitialSettings("Engine", 800, 600));

	DisplayWindow window(800, 600, "Bone Binder");

	// Implement engine loop with fixed update time step, and variable time stepped rendering
	// Has 1 frame delay to ensure smooth rendering (interpolation-only)

	while (!window.IsClosed())
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
			Update(kElapsedUpdateTime);
			lag -= kElapsedUpdateTime;
		}
		
		Draw(lag / kElapsedUpdateTime);

		window.SwapBuffers();
		window.UpdateClosed();
	}
}

double Engine::GetCurrentTime() const
{
	return (double)time(NULL);
}

void Engine::processInput()
{

}