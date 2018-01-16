#include "Game.h"

#include "States/StatePlaying.h"

Game::Game()
:   m_window    ({1280, 720}, "GameNameHere")
{
    m_window.setFramerateLimit(60);
    pushState<StatePlaying>(*this);
}

//Runs the main loop
void Game::run()
{
    constexpr unsigned TPS = 60; //ticks per seconds
    const sf::Time     timePerUpdate = sf::seconds(1.0f / float(TPS));
    unsigned ticks = 0;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag      = sf::Time::Zero;

    //Main loop of the game
    while (m_window.isOpen() && !m_states.empty()) {
        auto& state = getCurrentState();

        //Get times
        auto time = timer.getElapsedTime();
        auto elapsed = time - lastTime;

        lastTime = time;
        lag += elapsed;

        //Real time update
        state.handleInput();
        state.update(elapsed);
        counter.update();

        //Fixed time update
        while (lag >= timePerUpdate)
        {
            ticks++;
            lag -= timePerUpdate;
            state.fixedUpdate(elapsed);
        }

        //Render
        m_window.clear();
        state.render(m_window);
        counter.draw(m_window);
        m_window.display();


        //Handle window events
        handleEvent();
        tryPop();
    }
}

//Tries to pop the current game state
void Game::tryPop()
{
    if (m_shouldPop) {
        m_states.pop_back();
    }
}

//Handles window events, called every frame
void Game::handleEvent()
{
    sf::Event e;

    while (m_window.pollEvent(e)) {
        getCurrentState().handleEvent(e);
        switch (e.type) {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;

        }
    }
}

//Returns a reference to the current game state
StateBase& Game::getCurrentState()
{
    return *m_states.back();
}

//Flags a boolean for the game to pop state
void Game::popState()
{
    m_shouldPop = true;
}

//on tin
const sf::RenderWindow& Game::getWindow() const
{
    return m_window;
}
