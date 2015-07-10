#pragma once

#include "Control.h"
#include <vector>

class ContentManager;
class Font;
class Renderer;
class Texture2D;
class DisplayWindow;

class MenuBar : public Control
{
private:
	Font &mFont;
	std::vector<Control> mMenuItems;
	DisplayWindow &mWindow;
public:
	MenuBar(Texture2D &controlElements, Renderer &renderer, Font &font, DisplayWindow &window);
	~MenuBar();

	virtual void Draw() override;
};

