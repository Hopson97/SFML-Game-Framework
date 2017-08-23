#ifndef STACKMENU_H_INCLUDED
#define STACKMENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Widget.h"

namespace gui
{

class StackMenu
{
    public:
        StackMenu(const sf::Vector2f& origin);

        template <typename T, typename... Args>
        void addWidget(Args&&... args);

        void handleEvents   (sf::Event e);
        void render         (sf::RenderTarget& renderer);

    private:
        std::vector<std::unique_ptr<Widget>> m_widgets;
        sf::RectangleShape m_background;
        const sf::Vector2f m_origin;
};

template <typename T, typename... Args>
void StackMenu::addWidget(Args&&... args)
{
    m_widgets.push_back(std::make_unique<T>(std::forward<Args>(args)...));
}


}

#endif // STACKMENU_H_INCLUDED
