#include "Game.h"

Game::Game()
:   m_window    ({1280, 720}, "GameNameHere")
{

}

void Game::run()
{
    sf::Clock c;
    while (m_window.isOpen() && !m_states.empty())
    {
        auto deltaime = c.restart();

        auto& state = getCurrentState();

        state.handleInput();
        state.update(deltaime);

        m_window.clear();
        state.render(m_window);
        m_window.display();

        handleEvents();
        tryPop();
    }
}

void Game::tryPop()
{
    if (m_shouldPop)
    {
        m_states.pop_back();
    }
}

void Game::handleEvents()
{
    sf::Event e;

    while (m_window.pollEvent(e))
    {
        getCurrentState().handleEvent(e);
        switch (e.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;

        }
    }
}

StateBase& Game::getCurrentState()
{
    return *m_states.back();
}



void Game::popState()
{
    m_shouldPop = true;
}
