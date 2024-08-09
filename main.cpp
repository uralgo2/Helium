#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <fmt/color.h>

#include "helium/engine/engine.hpp"
#include "helium/engine/base_game.hpp"

#ifdef _WIN32
#include <Windows.h>
#endif

class SampleGame : public he::engine::BaseGame {
public:
    SampleGame(std::int32_t width, std::int32_t height, std::string title): BaseGame({
        width, height,
60, 0,
        std::move(title),
        false,
        true
    }) {}
    void OnRender(float deltaTime) override {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OnFrameBufferResize(const glm::ivec2 size) override {
        glViewport(0, 0, size.x, size.y);
    }
    void OnKeyDown(const he::engine::events::KeyboardKeyEventArgs &eventArgs) override {
        if(eventArgs.Key == he::engine::input::keyboard::Keys::A && !eventArgs.IsRepeat) {
            fmt::print(fg(fmt::color::green), "Okay, that's works fine!\n");
        }
        if(eventArgs.Key == he::engine::input::keyboard::Keys::Escape) {
            this->Close();
        }
        if(eventArgs.Key == he::engine::input::keyboard::Keys::E) {
            throw std::runtime_error("Exception!");
        }
    }
    void OnClose() override {
        fmt::println("Closing...");
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    try {
#ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
        #endif

        he::engine::HeliumEngine engine;
        auto* game = new SampleGame(1600, 900, "SampleGame");

        engine.Init();
        engine.Run(game);
    }
    catch (std::exception& e) {
        fmt::print(fg(fmt::color::red), "Error occured: {}\n", e.what());
    }
    return 0;
}
