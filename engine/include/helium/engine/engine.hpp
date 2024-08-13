//
// Created by uralg on 08.08.2024.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "helium/engine/base_game.hpp"
#include "phoenix/phoenix_render_engine.hpp"

class BaseGame;
namespace he::engine {
	class HeliumEngine {
		private:
		BaseGame* _game;
		phoenix::IPhoenixRenderEngine* _renderEngine;
	public:
		HeliumEngine(BaseGame* game, phoenix::IPhoenixRenderEngine* renderEngine);
		void Init();
		void Run();
	};
}
#endif //ENGINE_HPP
