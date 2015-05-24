#pragma once

#include "EngineDLL.h"
#include <string>

struct EngineInitialSettings
{
private:
	std::string mWindowTitle;
	int mWindowWidth;
	int mWindowHeight;

public:
	ENGINE_API EngineInitialSettings(std::string windowTitle, int windowWidth, int windowHeight);

	ENGINE_API std::string GetWindowTitle();
	ENGINE_API void SetWindowTitle(std::string windowTitle);
	ENGINE_API int GetWindowWidth();
	ENGINE_API void SetWindowWidth(int width);
	ENGINE_API int GetWindowHeight();
	ENGINE_API void SetWindowHeight(int height);
};