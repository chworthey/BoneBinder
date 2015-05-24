#pragma once

#include "EngineDLL.h"

#include <SDL2/SDL.h>
#include <string>

class DisplayWindow
{
private:
	SDL_Window *mWindow;
	SDL_GLContext mGLContext;
	bool mIsClosed;

public:
	ENGINE_API DisplayWindow(int width, int height, const std::string &title);
	ENGINE_API virtual ~DisplayWindow();

	ENGINE_API bool IsClosed() { return mIsClosed; }
	ENGINE_API void SwapBuffers();
	ENGINE_API void UpdateClosed();
private:
	DisplayWindow(const DisplayWindow &rhs) {}
	void operator=(const DisplayWindow &rhs) {}
};

