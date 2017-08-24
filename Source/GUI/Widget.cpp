#include "Widget.h"

namespace gui {

//Text
Widget::Text::Text()
{
    setCharacterSize (20);
    setOutlineColor  (sf::Color::Black);
    setFillColor     (sf::Color::White);
    setFont          (ResourceHolder::get().fonts.get("arial"));
}



//Rectangle
bool Widget::Rectangle::isRolledOn(const sf::RenderWindow& window) const
{
    auto pos = sf::Mouse::getPosition(window);
    return getGlobalBounds().contains(pos.x, pos.y);
}

bool Widget::Rectangle::isClicked  (sf::Event e, const sf::RenderWindow& window)
{
    if(isRolledOn(window))
    {
        if (e.type == sf::Event::MouseButtonPressed)
        {
            return e.mouseButton.button == sf::Mouse::Left;
        }
    }
    return false;
}

}
