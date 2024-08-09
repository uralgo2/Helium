//
// Created by uralg on 08.08.2024.
//

#include "helium/engine/engine.hpp"
#include "helium/engine/base_game.hpp"
#include <GLFW/glfw3.h>


namespace he::engine {
	void HeliumEngine::Init() {
	}

	void HeliumEngine::Run(BaseGame *game) {
		game->IsRunning = true;

		auto lastTime = glfwGetTime();

		while(game->IsRunning) {
			glfwPollEvents();

			const auto now = glfwGetTime();
			const auto deltaTime = now - lastTime;

			lastTime = now;

			game->OnRender(static_cast<float>(deltaTime));

			glfwSwapBuffers(game->_windowHandler);
		}
	}
} // render_engine
// hg