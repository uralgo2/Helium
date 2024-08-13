#ifndef KEYBOARD_MANAGER_HPP
#define KEYBOARD_MANAGER_HPP

#include "helium/engine/input/keyboard/keyboard_state.hpp"

namespace he::engine::input::keyboard
{
    class KeyboardManager {
    private:
        KeyboardState& _keyboardState;
    public:
        KeyboardManager(KeyboardState& state) : _keyboardState(state) {}
        constexpr bool IsKeyDown(Keys key) const {
            return _keyboardState.GetKeyState(key).State == KeyState::Pressed;
        }
        constexpr bool IsKeyUp(Keys key) const  {
            return _keyboardState.GetKeyState(key).State == KeyState::Pressed;
        }
        constexpr const KeyboardKeyState& GetKeyState(Keys key) const {
            return _keyboardState.GetKeyState(key);
        }
    };
} // namespace he::engine::input


#endif