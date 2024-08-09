//
// Created by uralg on 08.08.2024.
//

#ifndef BASE_GAME_HPP
#define BASE_GAME_HPP
#include "window_options.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "engine.hpp"
#include "events/keyboard_key_event_args.hpp"
#include "input/keyboard/keyboard_state.hpp"

namespace he::engine {
	class BaseGame {
	private:
		WindowOptions _windowOptions;
		GLFWwindow* _windowHandler;
		glm::ivec2 _windowSize;
		input::keyboard::KeyboardState _keyboardState;

	public:
		volatile bool IsRunning = false;
		explicit BaseGame(WindowOptions  windowOptions);

		virtual ~BaseGame();

		virtual void OnInit(){}
		virtual void OnLoad(){}
		virtual void OnUpdate(float deltaTime){}
		virtual void OnRender(float deltaTime){}
		virtual void OnFrameBufferResize(glm::ivec2 size){}
		virtual void OnClose(){}
		virtual void OnKeyDown(const events::KeyboardKeyEventArgs& eventArgs){}
		virtual void OnKeyUp(const events::KeyboardKeyEventArgs& eventArgs){}

		void Close();

		constexpr glm::ivec2 WindowSize() const {
			return _windowSize;
		}

		friend class HeliumEngine;
	};
} // engine
// he

#endif //BASE_GAME_HPP
