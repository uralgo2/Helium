//
// Created by uralg on 08.08.2024.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "base_game.hpp"
class BaseGame;
namespace he::engine {
	class HeliumEngine {
	public:
		void Init();
		void Run(BaseGame *game);
	};
}
#endif //ENGINE_HPP
