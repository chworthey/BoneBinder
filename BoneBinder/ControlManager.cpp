#include "ControlManager.h"

#include "ContentManager.h"
#include "Font.h"
#include "Renderer.h"

ControlManager::ControlManager(const ContentManager &contentManager, Renderer &renderer)
: mContentManager(contentManager),
mControlElements(contentManager.LoadTextureFromFile("./Resources/ControlElements.png")),
mRenderer(renderer)
{
}


ControlManager::~ControlManager()
{
}

std::shared_ptr<MenuBar> ControlManager::CreateMenuBar(DisplayWindow &window, Font &font)
{
	if (mControlElements)
		return std::shared_ptr<MenuBar>(new MenuBar(*mControlElements, mRenderer, font, window));
	else
		return std::shared_ptr<MenuBar>();
}
