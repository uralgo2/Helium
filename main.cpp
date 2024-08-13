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
        using namespace he::engine::input::keyboard;

        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OnFrameBufferResize(const glm::ivec2 size) override {
        glViewport(0, 0, size.x, size.y);
    }
    void OnKeyDown(const he::engine::events::KeyboardKeyEventArgs &eventArgs) override {
        using namespace he::engine::input::keyboard;
      
        if(eventArgs.Key == Keys::Escape) {
            this->Close();
        }
        if(eventArgs.Key == Keys::Space && !eventArgs.IsRepeat){
            glClearColor((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, 1);    
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

        auto* game = new SampleGame(1600, 900, "SampleGame");
        auto* renderEngine = new phoenix::OpenglRenderEngine();

        he::engine::HeliumEngine engine{game, (phoenix::IPhoenixRenderEngine*)renderEngine};
        
        engine.Init();
        engine.Run();
    }
    catch (std::exception& e) {
        fmt::print(fg(fmt::color::red), "Error occured: {}\n", e.what());
    }
    return 0;
}
