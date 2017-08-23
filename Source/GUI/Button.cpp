#include "Button.h"

#include <iostream>

namespace gui {

Button::Button()
{
    m_button.setFillColor({52, 152, 219});
    m_button.setSize({512, 128});

    m_text.setCharacterSize (40);
    m_text.setOutlineColor  (sf::Color::Black);
    m_text.setFillColor     (sf::Color::White);
    m_text.setFont          (ResourceHolder::get().fonts.get("arial"));

}

void Button::setFunction(std::function<void(void)>func)
{
    m_function = func;
}

void Button::setText (const std::string& str)
{
    m_text.setString(str);
    updateText();
}

void Button::setTexture (const sf::Texture& tex)
{
    m_button.setTexture(&tex);
}

void Button::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
    auto pos = sf::Mouse::getPosition(window);

    if (m_button.getGlobalBounds().contains(pos.x, pos.y))
    {
        if (e.type == sf::Event::MouseButtonPressed)
        {
            if (e.mouseButton.button == sf::Mouse::Left)
            {
                m_function();
            }
        }
    }
}

void Button::render(sf::RenderTarget& renderer)
{
    renderer.draw(m_button);
    renderer.draw(m_text);
}

void Button::setPosition(const sf::Vector2f& pos)
{
    m_position = pos;

    m_button.setPosition(m_position);
    m_text.setPosition  (m_position);

    updateText();
}

void Button::updateText()
{
    m_text.setOrigin(m_text.getGlobalBounds().width  / 2,
                     m_text.getGlobalBounds().height / 2);

    m_text.move(m_button.getGlobalBounds().width  / 2,
                m_button.getGlobalBounds().height / 2.5);
}


sf::Vector2f Button::getSize() const
{
    return {256, 128};
}

}
