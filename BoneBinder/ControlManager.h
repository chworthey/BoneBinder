#pragma once

#include "MenuBar.h"
#include "Texture2D.h"
#include <memory>

class ContentManager;
class DisplayWindow;
class Font;
class Renderer;

class ControlManager
{
private:
	const ContentManager &mContentManager;
	Renderer &mRenderer;
	std::shared_ptr<Texture2D> mControlElements;

public:
	ControlManager(const ContentManager &contentManager, Renderer &renderer);
	~ControlManager();

	std::shared_ptr<MenuBar> CreateMenuBar(DisplayWindow &window, Font &font);
};

