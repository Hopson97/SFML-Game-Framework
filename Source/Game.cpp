#include "Game.h"

Game::Game()
:   m_window    ({1280, 720}, "GameNameHere")
{

}

void Game::run()
{
    while (m_window.isOpen())
    {
        m_window.clear();



        m_window.display();
        handleEvents();
        tryPop();
    }
}

void Game::tryPop()
{

}

void Game::handleEvents()
{

}


void Game::popState()
{
    m_shouldPop = true;
}
