#pragma once

#include <SFML/Graphics.hpp>

/**
    Class that represents a toggle key.
    The key can only be pressed every 0.2s
*/
class ToggleKey
{
    public:
        ToggleKey(sf::Keyboard::Key);

        bool isKeyPressed();

    private:
        sf::Keyboard::Key m_key;
        sf::Clock m_delayTimer;

};
