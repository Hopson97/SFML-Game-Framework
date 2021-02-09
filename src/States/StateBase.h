#pragma once

#include <SFML/Graphics.hpp>

#include "../Util/NonCopyable.h"

class Game;

class StateBase : public NonCopyable
{
    public:
        StateBase(Game& game)
            : m_pGame(&game)
        {}

        virtual ~StateBase() = default;

        virtual void handleEvent(sf::Event) {}
        virtual void handleInput() = 0;
        virtual void update(sf::Time) {}
        virtual void fixedUpdate(sf::Time) {}
        virtual void render(sf::RenderTarget& renderer) = 0;

    protected:
        Game* m_pGame;
};
