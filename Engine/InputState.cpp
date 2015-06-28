#include "InputState.h"

InputState::InputState(std::map<KeyboardKey::KeyboardKey, bool> keyMap)
: mKeyMap(keyMap)
{
}

InputState::InputState()
: mKeyMap(std::map<KeyboardKey::KeyboardKey, bool>())
{
}

bool InputState::GetIsKeyboardKeyDown(const KeyboardKey::KeyboardKey &key)
{
	if (mKeyMap.find(key) == mKeyMap.end())
		return false;

	return mKeyMap[key];
}
