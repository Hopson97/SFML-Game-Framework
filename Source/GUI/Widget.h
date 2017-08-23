#ifndef GUIWIDGET_H_INCLUDED
#define GUIWIDGET_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "../ResourceManager/ResourceHolder.h"

namespace gui
{
    class Widget
    {
        public:
            virtual void handleEvent(sf::Event e, const sf::RenderWindow& window);

            virtual void render(sf::RenderTarget& renderer) = 0;

            virtual void setPosition(const sf::Vector2f& pos) = 0;

            virtual sf::Vector2f getSize() const = 0;
    };
}

#endif // GUIWIDGET_H_INCLUDED
