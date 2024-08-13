//
// Created by uralg on 09.08.2024.
//

#ifndef KEYBOARD_STATE_HPP
#define KEYBOARD_STATE_HPP
#include <unordered_map>

#include "helium/engine/input/keyboard/keyboard_key_state.hpp"
#include "helium/engine/input/keyboard/keys.hpp"


namespace he::engine::input::keyboard {

struct KeyboardState {
	private:
		std::unordered_map<Keys, KeyboardKeyState> _keyStates;

	public:
		inline void SetKeyState(Keys key, const KeyboardKeyState& state) {
			_keyStates.insert_or_assign(key, state);
		}
		const KeyboardKeyState& GetKeyState(const Keys key) {
			if(_keyStates.find(key) == _keyStates.end())
				_keyStates.insert({
					key,
					KeyboardKeyState(
						key,
						KeyState::None,
						KeyModifiers::None,
						0,
						false
						)
					});

			return _keyStates.at(key);
		}
};

} // keyboard
// input
// engine
// he

#endif //KEYBOARD_STATE_HPP
