#pragma once

#include "EngineDLL.h"

#include <SDL2/SDL.h>
#include <string>

enum MessageType
{
	INFORMATION_MESSAGE_TYPE,
	WARNING_MESSAGE_TYPE,
	ERROR_MESSAGE_TYPE
};

class DisplayWindow
{
private:
	SDL_Window *mWindow;
	SDL_GLContext mGLContext;
	bool mIsClosed;
	int mWidth;
	int mHeight;

public:
	ENGINE_API DisplayWindow(int width, int height, const std::string &title);
	ENGINE_API ~DisplayWindow();

	ENGINE_API int GetWidth() const;
	ENGINE_API int GetHeight() const;
	ENGINE_API float GetApectPixelRatio() const;

	bool IsClosed() { return mIsClosed; }
	void SwapBuffers();
	void UpdateClosed();

	Uint32 GetTicks() const;

	void ShowNotificationMessageBox(std::string message, MessageType type);

	DisplayWindow operator=(const DisplayWindow &rhs);
private:
	DisplayWindow(const DisplayWindow &rhs) {}
};

