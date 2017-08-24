#ifndef STACKMENU_H_INCLUDED
#define STACKMENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Widget.h"
#include "../Util/NonCopyable.h"

namespace gui
{

class StackMenu : public NonCopyable
{
    public:
        StackMenu(const sf::RenderWindow& window);
        StackMenu(const sf::Vector2f& position);

        StackMenu(StackMenu&& other);
        StackMenu& operator =(StackMenu&& other);


        ~StackMenu() = default;
        void addWidget(std::unique_ptr<Widget>);

        void handleEvent   (sf::Event e, const sf::RenderWindow& window);
        void render         (sf::RenderTarget& renderer);

    private:
        void initWidget(Widget& w);

        std::vector<std::unique_ptr<Widget>> m_widgets;
        sf::RectangleShape m_background;

        sf::Vector2f m_basePosition;
        sf::Vector2f m_baseSize;
};

}

#endif // STACKMENU_H_INCLUDED
