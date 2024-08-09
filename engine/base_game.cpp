//
// Created by uralg on 08.08.2024.
//

#include "helium/engine/base_game.hpp"

#include <fmt/std.h>
#include <stdexcept>
#include <utility>

#include "helium/engine/events/keyboard_key_event_args.hpp"


namespace he::engine {
	BaseGame::BaseGame(WindowOptions  windowOptions) : _windowOptions(std::move(windowOptions)) {
		if(!glfwInit())
			throw std::runtime_error("Couldn't initialize GLFW.");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, _windowOptions.Resizeable);

		_windowHandler = glfwCreateWindow(
			_windowOptions.Width, _windowOptions.Height,
			_windowOptions.Title.c_str(),
			nullptr,
			nullptr
			);
		if (_windowHandler == nullptr)
		{
			const char* error = nullptr;

			glfwGetError(&error);
			throw std::runtime_error(fmt::format("Failed to create GLFW window. {}", error));

		}
		glfwMakeContextCurrent(_windowHandler);

		glfwSwapInterval(_windowOptions.VSync == true ? 1 : 0);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw std::runtime_error("Couldn't initialize GLEW.");

		glfwGetFramebufferSize(_windowHandler, &_windowSize.x, &_windowSize.y);

		glViewport(0, 0, _windowSize.x, _windowSize.y);

		glfwSetWindowUserPointer(_windowHandler, this);

		glfwSetFramebufferSizeCallback(_windowHandler, [](GLFWwindow* window, int width, int height) {
			auto* game = static_cast<BaseGame*>(glfwGetWindowUserPointer(window));

			game->OnFrameBufferResize({width, height});
		});
		glfwSetKeyCallback(_windowHandler, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			auto* game = static_cast<BaseGame*>(glfwGetWindowUserPointer(window));

			auto managedKey = static_cast<input::keyboard::Keys>(key);
			auto isRepeated = action == GLFW_REPEAT;
			auto modifiers = static_cast<input::keyboard::KeyModifiers>(mods);
			auto state = action == GLFW_PRESS ? input::KeyState::Pressed
									: action == GLFW_RELEASE ? input::KeyState::Released
									: input::KeyState::None;

			if(isRepeated) {
				auto lastState = game->_keyboardState.GetKeyState(managedKey);

				state = lastState.State;
			}

			game->_keyboardState.SetKeyState(managedKey, input::keyboard::KeyboardKeyState(managedKey, state, modifiers, scancode, isRepeated));

			const auto keyEventArgs = events::KeyboardKeyEventArgs(managedKey, modifiers, scancode, isRepeated);

			if(state == input::KeyState::Pressed)
				game->OnKeyDown(keyEventArgs);
			else if(state == input::KeyState::Released)
				game->OnKeyUp(keyEventArgs);

		});

		glfwSetWindowCloseCallback(_windowHandler, [](GLFWwindow* window) {
			auto* game = static_cast<BaseGame*>(glfwGetWindowUserPointer(window));
			game->Close();
		});
	}

	BaseGame::~BaseGame() {
		glfwDestroyWindow(_windowHandler);
		glfwTerminate();
	}

	void BaseGame::Close() {
		glfwSetWindowShouldClose(_windowHandler, GLFW_TRUE);
		IsRunning = false;
		OnClose();
	}
} // engine
// he