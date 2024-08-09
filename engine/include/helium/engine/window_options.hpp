//
// Created by uralg on 08.08.2024.
//

#ifndef WINDOW_OPTIONS_HPP
#define WINDOW_OPTIONS_HPP
#include <cinttypes>
#include <string>

namespace he::engine {
	struct WindowOptions {
		std::int32_t Width, Height;
		std::int32_t UpdatesPerSecond, RendersPerSecond;
		std::string Title;
		bool VSync = true;
		bool Resizeable = true;
	};
}
#endif //WINDOW_OPTIONS_HPP
