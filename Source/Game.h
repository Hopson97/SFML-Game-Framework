#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();

        void run();

        template<typename T, typename... Args>
        void pushState(Args&&... args);

        void popState();

    private:
        void handleEvents();
        void tryPop();


        sf::RenderWindow m_window;




        bool m_shouldPop = false;

};

template<typename T, typename... Args>
void Game::pushState(Args&&... args)
{

}

#endif // GAME_H_INCLUDED
