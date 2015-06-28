#include "InputManager.h"
#include "Assert.h"

InputManager::InputManager()
: mKeyMap()
{
}


InputManager::~InputManager()
{
}

void InputManager::DoKeyUpEvent(const SDL_KeyboardEvent &key)
{
	mKeyMap[key.keysym.sym] = false;
}

void InputManager::DoKeyDownEvent(const SDL_KeyboardEvent &key)
{
	mKeyMap[key.keysym.sym] = true;
}

InputState InputManager::GenerateInputState()
{
	std::map<KeyboardKey::KeyboardKey, bool> keyMap;

	for (auto key : mKeyMap)
	{
		if (key.second)
		{
			switch (key.first)
			{
			case SDLK_a:
				keyMap[KeyboardKey::A] = true;
				break;
			case SDLK_b:
				keyMap[KeyboardKey::B] = true;
				break;
			case SDLK_c:
				keyMap[KeyboardKey::C] = true;
				break;
			case SDLK_d:
				keyMap[KeyboardKey::D] = true;
				break;
			case SDLK_e:
				keyMap[KeyboardKey::E] = true;
				break;
			case SDLK_f:
				keyMap[KeyboardKey::F] = true;
				break;
			case SDLK_g:
				keyMap[KeyboardKey::G] = true;
				break;
			case SDLK_h:
				keyMap[KeyboardKey::H] = true;
				break;
			case SDLK_i:
				keyMap[KeyboardKey::I] = true;
				break;
			case SDLK_j:
				keyMap[KeyboardKey::J] = true;
				break;
			case SDLK_k:
				keyMap[KeyboardKey::K] = true;
				break;
			case SDLK_l:
				keyMap[KeyboardKey::L] = true;
				break;
			case SDLK_m:
				keyMap[KeyboardKey::M] = true;
				break;
			case SDLK_n:
				keyMap[KeyboardKey::N] = true;
				break;
			case SDLK_o:
				keyMap[KeyboardKey::O] = true;
				break;
			case SDLK_p:
				keyMap[KeyboardKey::P] = true;
				break;
			case SDLK_q:
				keyMap[KeyboardKey::Q] = true;
				break;
			case SDLK_r:
				keyMap[KeyboardKey::R] = true;
				break;
			case SDLK_s:
				keyMap[KeyboardKey::S] = true;
				break;
			case SDLK_t:
				keyMap[KeyboardKey::T] = true;
				break;
			case SDLK_u:
				keyMap[KeyboardKey::U] = true;
				break;
			case SDLK_v:
				keyMap[KeyboardKey::V] = true;
				break;
			case SDLK_w:
				keyMap[KeyboardKey::W] = true;
				break;
			case SDLK_x:
				keyMap[KeyboardKey::X] = true;
				break;
			case SDLK_y:
				keyMap[KeyboardKey::Y] = true;
				break;
			case SDLK_z:
				keyMap[KeyboardKey::Z] = true;
				break;
			case SDLK_1:
				keyMap[KeyboardKey::ONE] = true;
				break;
			case SDLK_2:
				keyMap[KeyboardKey::TWO] = true;
				break;
			case SDLK_3:
				keyMap[KeyboardKey::THREE] = true;
				break;
			case SDLK_4:
				keyMap[KeyboardKey::FOUR] = true;
				break;
			case SDLK_5:
				keyMap[KeyboardKey::FIVE] = true;
				break;
			case SDLK_6:
				keyMap[KeyboardKey::SIX] = true;
				break;
			case SDLK_7:
				keyMap[KeyboardKey::SEVEN] = true;
				break;
			case SDLK_8:
				keyMap[KeyboardKey::EIGHT] = true;
				break;
			case SDLK_9:
				keyMap[KeyboardKey::NINE] = true;
				break;
			case SDLK_0:
				keyMap[KeyboardKey::ZERO] = true;
				break;
			case SDLK_LEFT:
				keyMap[KeyboardKey::LEFT] = true;
				break;
			case SDLK_RIGHT:
				keyMap[KeyboardKey::RIGHT] = true;
				break;
			case SDLK_UP:
				keyMap[KeyboardKey::UP] = true;
				break;
			case SDLK_DOWN:
				keyMap[KeyboardKey::DOWN] = true;
				break;
			case SDLK_LCTRL:
			case SDLK_RCTRL:
				keyMap[KeyboardKey::CONTROL] = true;
				break;
			case SDLK_LSHIFT:
			case SDLK_RSHIFT:
				keyMap[KeyboardKey::SHIFT] = true;
				break;
			case SDLK_LALT:
			case SDLK_RALT:
				keyMap[KeyboardKey::ALT] = true;
				break;
			case SDLK_SPACE:
				keyMap[KeyboardKey::SPACE] = true;
				break;
			case SDLK_TAB:
				keyMap[KeyboardKey::TAB] = true;
				break;
			case SDLK_BACKSPACE:
				keyMap[KeyboardKey::BACKSPACE] = true;
				break;
			default:
				break;
			}
		}
	}

	return InputState(keyMap);
}
