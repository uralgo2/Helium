//
// Created by uralg on 09.08.2024.
//

#ifndef MODIFIERS_HPP
#define MODIFIERS_HPP
#include <cinttypes>
namespace he::engine::input::keyboard {
	enum class KeyModifiers : std::int8_t {
		None     = 0x0000,
		Shift    = 0x0001,
		Control  = 0x0002,
		Alt      = 0x0004,
		Super    = 0x0008,
		CapsLock = 0x0010,
		NumLock  = 0x0020
	};

	inline bool HasFlag(KeyModifiers _this, KeyModifiers flag) {
		return (static_cast<int>(_this) & static_cast<int>(flag)) != 0;
	}
}
#endif //MODIFIERS_HPP
