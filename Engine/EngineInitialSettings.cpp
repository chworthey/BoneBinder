#include "EngineInitialSettings.h"

EngineInitialSettings::EngineInitialSettings(std::string windowTitle, int windowWidth, int windowHeight)
	: mWindowTitle(windowTitle),
	mWindowWidth(windowWidth),
	mWindowHeight(windowHeight)
{
}

std::string EngineInitialSettings::GetWindowTitle()
{
	return mWindowTitle;
}
void EngineInitialSettings::SetWindowTitle(std::string windowTitle)
{
	mWindowTitle = windowTitle;
}
int EngineInitialSettings::GetWindowWidth()
{
	return mWindowWidth;
}
void EngineInitialSettings::SetWindowWidth(int width)
{
	mWindowWidth = width;
}
int EngineInitialSettings::GetWindowHeight()
{
	return mWindowHeight;
}
void EngineInitialSettings::SetWindowHeight(int height)
{
	mWindowHeight = height;
}