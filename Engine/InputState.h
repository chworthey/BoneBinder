#pragma once

#include "EngineDLL.h"
#include <map>

namespace KeyboardKey
{
	enum KeyboardKey
	{
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		SPACE, ENTER, CONTROL, SHIFT, ALT,
		ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO,
		TAB, BACKSPACE, LEFT, RIGHT, UP, DOWN
	};
}

class InputState
{
private:
	std::map<KeyboardKey::KeyboardKey, bool> mKeyMap;
public:
	InputState();
	InputState(std::map<KeyboardKey::KeyboardKey, bool> keyMap);
	ENGINE_API bool GetIsKeyboardKeyDown(const KeyboardKey::KeyboardKey &key);
};

