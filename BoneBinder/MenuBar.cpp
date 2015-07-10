#include "MenuBar.h"

#include "DisplayWindow.h"
#include "Font.h"
#include "Rectangle.h"
#include "Renderer.h"
#include "Texture2D.h"

MenuBar::MenuBar(Texture2D &controlElements, Renderer &renderer, Font &font, DisplayWindow &window)
: Control(controlElements, renderer),
mFont(font),
mMenuItems(),
mWindow(window)
{
}


MenuBar::~MenuBar()
{
}

void MenuBar::Draw()
{
	GetRenderer().RenderTexture(GetControlElements(), Rectangle(0.0f, 0.0f, (float)mWindow.GetWidth(), 20.0f), 
		GetSourceArea(0, 0), glm::vec4(1.0f));
}
