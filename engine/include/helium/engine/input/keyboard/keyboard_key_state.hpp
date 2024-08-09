//
// Created by uralg on 09.08.2024.
//

#ifndef KEYBOARD_KEY_STATE_HPP
#define KEYBOARD_KEY_STATE_HPP

#include "helium/engine/input/key_state.hpp"
#include "helium/engine/input/keyboard/keys.hpp"
#include "helium/engine/input/keyboard/modifiers.hpp"


namespace he::engine::input::keyboard {

struct KeyboardKeyState {
	KeyState State;
	Keys Key;
	KeyModifiers Modifiers;
	std::int32_t Scancode;
	bool IsRepeat;
	KeyboardKeyState(const Keys key, const KeyState state, const KeyModifiers modifiers, const std::int32_t scancode, const bool isRepeat) :
	Key(key), State(state), Modifiers(modifiers), Scancode(scancode), IsRepeat(isRepeat)
	{}
	KeyboardKeyState(const KeyboardKeyState& state) = default;

	constexpr bool Pressed() const {
		return State == KeyState::Pressed;
	}
	constexpr bool Released() const {
		return State == KeyState::Released;
	}
	constexpr bool Alt() const {
		return input::keyboard::HasFlag(Modifiers, input::keyboard::KeyModifiers::Alt);
	}

	constexpr bool Control() const {
		return input::keyboard::HasFlag(Modifiers, input::keyboard::KeyModifiers::Control);
	}

	constexpr bool Shift() const {
		return input::keyboard::HasFlag(Modifiers, input::keyboard::KeyModifiers::Shift);
	}

	constexpr bool Command() const {
		return input::keyboard::HasFlag(Modifiers, input::keyboard::KeyModifiers::Super);
	}
};

} // keyboard
// input
// engine
// he

#endif //KEYBOARD_KEY_STATE_HPP
