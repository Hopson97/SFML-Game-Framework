#include "Widget.h"

namespace gui {

    // Text
    Widget::Text::Text()
    {
        setCharacterSize(25);
        setOutlineColor(sf::Color::Black);
        setFillColor(sf::Color::White);
        setFont(ResourceHolder::get().fonts.get("arial"));
    }

    bool Widget::Rectangle::isRolledOn(const sf::RenderWindow& window) const
    {
        auto pos = sf::Mouse::getPosition(window);
        return getGlobalBounds().contains((float)pos.x, (float)pos.y);
    }

    bool Widget::Rectangle::isClicked(sf::Event e, const sf::RenderWindow& window)
    {
        if (isRolledOn(window)) {
            if (e.type == sf::Event::MouseButtonPressed) {
                return e.mouseButton.button == sf::Mouse::Left;
            }
        }
        return false;
    }

} // namespace gui
