#pragma once

#include "EngineDLL.h"
#include <map>
#include <glm/glm.hpp>

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

namespace MouseButton
{
	enum MouseButton
	{
		LEFT, MIDDLE, RIGHT
	};
}

class InputState
{
private:
	std::map<KeyboardKey::KeyboardKey, bool> mKeyMap;
	glm::vec2 mMousePosition;
	bool mMouseLeftButtonDown;
	bool mMouseMiddleButtonDown;
	bool mMouseRightButtonDown;
	int mMouseScrollPosition;

public:
	InputState();
	InputState(std::map<KeyboardKey::KeyboardKey, bool> keyMap, glm::vec2 mousePosition,
		bool mouseLeftButtonDown, bool mouseMiddleButtonDown, bool mouseRightButtonDown,
		int mouseScrollPosition);
	ENGINE_API bool GetIsKeyboardKeyDown(const KeyboardKey::KeyboardKey &key);
	ENGINE_API glm::vec2 GetMousePosition() const;
	ENGINE_API bool GetIsMouseButtonDown(const MouseButton::MouseButton &button);
	ENGINE_API int GetMouseScrollPosition() const;
};

