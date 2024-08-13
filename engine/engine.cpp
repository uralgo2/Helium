//
// Created by uralg on 08.08.2024.
//

#include "helium/engine/engine.hpp"
#include "helium/engine/base_game.hpp"
#include <GLFW/glfw3.h>


namespace he::engine {
	HeliumEngine::HeliumEngine(BaseGame* game, phoenix::IPhoenixRenderEngine* renderEngine) : _game(game), _renderEngine(renderEngine)
		{

		}
	void HeliumEngine::Init() {
		_renderEngine->Init();
		_game->OnInit();
	}

	void HeliumEngine::Run() {
		_game->IsRunning = true;

		auto lastTime = glfwGetTime();

		while(_game->IsRunning) {
			glfwPollEvents();

			const auto now = glfwGetTime();
			const auto deltaTime = now - lastTime;

			lastTime = now;

			_game->OnRender(static_cast<float>(deltaTime));

			glfwSwapBuffers(_game->_windowHandler);
		}
	}
} // render_engine
// hg