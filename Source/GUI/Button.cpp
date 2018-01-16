#include "Button.h"

#include <iostream>

namespace gui {

Button::Button(ButtonSize s)
{
    m_button.setFillColor({52, 152, 219});
    switch (s) {
        case ButtonSize::Wide:
            m_button.setSize({256, 64});
            break;

        case ButtonSize::Small:
            m_button.setSize({128, 64});
            break;
    }

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

    switch(e.type) {
        case sf::Event::MouseButtonPressed:
            switch(e.mouseButton.button) {
                case sf::Mouse::Left:
                    if (m_button.getGlobalBounds().contains(pos.x, pos.y)) {
                        m_function();
                    }

                default:
                    break;
            }

        default:
            break;
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
    return m_button.getSize();
}

}
