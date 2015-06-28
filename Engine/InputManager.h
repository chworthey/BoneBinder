#pragma once

#include "EngineDLL.h"
#include <SDL2/SDL.h>
#include <map>
#include "InputState.h"

class InputManager
{
private:
	std::map<SDL_Keycode, bool> mKeyMap;

public:
	ENGINE_API InputManager();
	ENGINE_API ~InputManager();

	void DoKeyUpEvent(const SDL_KeyboardEvent &key);
	void DoKeyDownEvent(const SDL_KeyboardEvent &key);
	InputState GenerateInputState();
};

