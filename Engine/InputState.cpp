#include "InputState.h"

InputState::InputState(std::map<KeyboardKey::KeyboardKey, bool> keyMap, glm::vec2 mousePosition,
	bool mouseLeftButtonDown, bool mouseMiddleButtonDown, bool mouseRightButtonDown,
	int mouseScrollPosition)
: mKeyMap(keyMap),
mMousePosition(mousePosition),
mMouseLeftButtonDown(mouseLeftButtonDown),
mMouseMiddleButtonDown(mouseMiddleButtonDown),
mMouseRightButtonDown(mouseRightButtonDown),
mMouseScrollPosition(mouseScrollPosition)
{
}

InputState::InputState()
: mKeyMap(std::map<KeyboardKey::KeyboardKey, bool>()),
mMousePosition(0.0f, 0.0f),
mMouseLeftButtonDown(false),
mMouseMiddleButtonDown(false),
mMouseRightButtonDown(false),
mMouseScrollPosition(0)
{
}

bool InputState::GetIsKeyboardKeyDown(const KeyboardKey::KeyboardKey &key)
{
	if (mKeyMap.find(key) == mKeyMap.end())
		return false;

	return mKeyMap[key];
}

glm::vec2 InputState::GetMousePosition() const
{
	return mMousePosition;
}

bool InputState::GetIsMouseButtonDown(const MouseButton::MouseButton &button)
{
	switch (button)
	{
	case MouseButton::LEFT:
		return mMouseLeftButtonDown;
	case MouseButton::MIDDLE:
		return mMouseMiddleButtonDown;
	case MouseButton::RIGHT:
		return mMouseRightButtonDown;
	default:
		return false;
	}
}

int InputState::GetMouseScrollPosition() const
{
	return mMouseScrollPosition;
}
