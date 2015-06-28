#pragma once

#include "EngineDLL.h"
#include <SDL2/SDL.h>
#include <map>
#include "InputState.h"
#include <glm/glm.hpp>

class InputManager
{
private:
	std::map<SDL_Keycode, bool> mKeyMap;
	glm::vec2 mMousePosition;
	bool mMouseLeftButtonDown;
	bool mMouseRightButtonDown;
	bool mMouseMiddleButtonDown;
	int mMouseScrollPosition;

public:
	ENGINE_API InputManager();
	ENGINE_API ~InputManager();

	void DoKeyUpEvent(const SDL_KeyboardEvent &key);
	void DoKeyDownEvent(const SDL_KeyboardEvent &key);
	void DoMouseMovementEvent(const SDL_MouseMotionEvent &movement);
	void DoMouseButtonEvent(const SDL_MouseButtonEvent &mouseDown);
	void DoMouseWheelEvent(const SDL_MouseWheelEvent &wheel);
	InputState GenerateInputState();
};

