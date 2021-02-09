#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui/imgui.h>
#include <imgui_sfml/imgui-SFML.h>
#include "Util/FPSCounter.h"

int main()
{
    sf::RenderWindow window({1280, 720}, "Game");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    // Set up time stamp stuff
    const unsigned TICKS_PER_SEC = 30;
    const sf::Time TIME_PER_UPDATE =
        sf::seconds(1.0f / static_cast<float>(TICKS_PER_SEC));
    unsigned ticks = 0;

    sf::Clock timer;
    sf::Clock dt;
    auto lastTime = sf::Time::Zero;
    auto lag = sf::Time::Zero;

    // Misc
    FPSCounter counter;

    // Main loop of the game
    while (window.isOpen()) {
        // auto& state = getCurrentState();

        sf::Event e;
        while (window.pollEvent(e)) {
            ImGui::SFML::ProcessEvent(e);
            // state.handleEvent(e);
            switch (e.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        // Get times
        auto time = timer.getElapsedTime();
        auto elapsed = time - lastTime;
        lastTime = time;
        lag += elapsed;

        // Real time update
        // state.handleInput();
        // state.update(elapsed);
        counter.update();
        ImGui::SFML::Update(window, dt.restart());

        ImGui::ShowDemoWindow();

        // Fixed time update
        while (lag >= TIME_PER_UPDATE) {
            ticks++;
            lag -= TIME_PER_UPDATE;
            // state.fixedUpdate(elapsed);
        }

        // Render
        window.clear();
        ImGui::SFML::Render(window);
        // state.render(m_window);
        counter.draw(window);
        window.display();

        // Handle window events
        // handleEvent();
        // tryPop();
    }
    ImGui::SFML::Shutdown();
}
