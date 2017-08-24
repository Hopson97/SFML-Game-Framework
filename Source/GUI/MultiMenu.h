#ifndef MULTIMENU_H_INCLUDED
#define MULTIMENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <utility>

#include "Widget.h"
#include "StackMenu.h"
#include "Button.h"

namespace gui
{

class MultiMenu
{
    public:
        MultiMenu(const sf::RenderWindow& window);

        void addWidget  (unsigned tab, std::unique_ptr<Widget>);
        void addTab     (const std::string& buttonText);

        void handleEvent   (sf::Event e, const sf::RenderWindow& window);
        void render         (sf::RenderTarget& renderer);

    private:
        std::vector<std::pair<Button, StackMenu>> m_tabs;
        unsigned m_activeTab = 0;

        sf::RectangleShape m_background;
        sf::Vector2f m_basePosition;
        sf::Vector2f m_baseSize;
};




}


#endif // MULTIMENU_H_INCLUDED
