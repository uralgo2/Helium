//
// Created by uralg on 09.08.2024.
//

#ifndef ON_KEY_DOWN_EVENT_HPP
#define ON_KEY_DOWN_EVENT_HPP
#include <cinttypes>

#include "helium/engine/input/keyboard/keys.hpp"
#include "helium/engine/input/keyboard/modifiers.hpp"

namespace he::engine::events {
	struct KeyboardKeyEventArgs {
		input::keyboard::Keys Key;
		input::keyboard::KeyModifiers Modifiers;
		std::int32_t Scancode;
		bool IsRepeat;

		KeyboardKeyEventArgs(const input::keyboard::Keys key, input::keyboard::KeyModifiers modifiers, std::int32_t scancode, bool isRepeat) :
	Key(key), Modifiers(modifiers), Scancode(scancode), IsRepeat(isRepeat)
		{}

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
}
#endif //ON_KEY_DOWN_EVENT_HPP
